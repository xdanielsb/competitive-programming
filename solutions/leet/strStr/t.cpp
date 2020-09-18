#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:

    vector < int > compute( const string &needle){
      int n = needle.size();
      vector< int > p(n);
      p[0] = 0;
      for( int i = 1; i < n; i++){
        p[i] = p[i-1];
        while( p[i] > 0 && needle[i] != needle[p[i]]){
          p[i] = p[ p[i] - 1];
        }
        if( needle[i] == needle[p[i]]){
          p[i]++;
        }
      }
      return p;
    }

    int strStr(string haystack, string needle) {
      //greedy solution
      int n = (int) haystack.size();
      int m = (int) needle.size();
      if( m == 0) return 0;
      vector< int > p = compute( needle );
      int s = 0;
      for( int i = 0; i < n; i++){
        while( s > 0 && haystack[i] != needle[s]){
          s = p[s - 1];
        }
        if( haystack[i] == needle[s]){
          s++;
        }
        if( s == m) return i -m +1;
      }
      return -1;
    }
};
