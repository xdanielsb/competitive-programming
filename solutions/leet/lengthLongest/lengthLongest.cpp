#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
  int n = (int) s.size();
  if( n == 0 ) return 0;
  if( n == 1 ) return 1;
  int l = 0, r = 0;
  unordered_map<char, int> cnt;
  cnt[s[0]] = 1;
  int ans = 1;
  while( r < n-1 ){
    if(r < n-1 && cnt[s[r]] == 1){
      cnt[s[++r]]++;
      if( cnt[s[r]] == 1) 
        ans = max(ans, r-l+1);
    }
    while(l <=r && cnt[s[r]]>1){
      cnt[s[l++]]--;
    }
  }
  return ans;
}
int main(){
  string s = "abcabcbb";
  int ans =  lengthOfLongestSubstring( s );
  cout << ans <<endl;
}
