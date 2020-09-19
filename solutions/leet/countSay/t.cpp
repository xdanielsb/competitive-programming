#include<bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
  if( n == 1) return "1";
  string s = countAndSay( n - 1);
  string ans = "";
  int ns = (int) s.size();
  int cnt = 1;
  s.push_back('$');
  for( int i = 1; i <= ns; i++){
    if( s[i-1] != s[i] ){
      ans += to_string(cnt) + (s[i-1]);
      cnt = 1;
    }else{
      cnt++;
    }
  }
  return ans;
}
int main(){
  string ans = countAndSay(6);
  cout << ans <<endl;
}
