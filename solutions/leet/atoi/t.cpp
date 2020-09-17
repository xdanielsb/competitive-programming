#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int myAtoi(string str) {
  ll ans = 0;
  int n = (int) str.size();
  int sign = 1;
  // discard with space
  int i = 0; // current pos in the string
  while(str[i] == ' '){
    i++;
  }
  if( isalpha(str[i])) return 0;
  // check if there is a sign
  if( i < n-1 && isdigit(str[i+1]) && str[i] == '-') {
    sign = -1;
    i++;
  }
  if( str[i] == '+') i++;

  for( ; i< n; i++){
    if(!isdigit(str[i])) break;
    ans  = ans * 10 + (str[i] - '0');
    if( sign > 0 && ans > INT_MAX) return INT_MAX;
    else if (sign < 0 && -ans < INT_MIN) return INT_MIN;
  }
  return ans * sign;
}
int main(){
  string s = "   -42";
  int ans = myAtoi(s);
  cout << ans << endl;
}
