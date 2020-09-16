#include<bits/stdc++.h>
using namespace std;
int reverse(int _x) {
  long long x = _x;
  long long ans = 0;
  int sign = 1;
  if( x < 0 ){
    sign = -1;
    x = -x;
  }
  while( x > 0 ){
    ans = ans * 10ll + (x%10);
    x = x / 10;
  }
  if( abs(ans) > INT_MAX) return 0;
  return ans * sign;
}
int main(){

  int x = -2131231;
  cout << reverse(x) << endl;

}
