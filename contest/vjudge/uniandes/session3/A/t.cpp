#include <iostream>
#include<string.h>
#define endl '\n'

using namespace std;
typedef long long ll;
int dp[35][8];
int n;
int solve( int i, int msk ){
  if( i >= n  ) return msk == 0 ;
  if(~dp[i][msk]) return dp[i][msk];
  int &ans = dp[i][msk];
  if( msk ==0 ) ans= solve( i+1, 4) + solve( i+1, 1) + solve( i+1, 7);
  else if( msk == 1) ans= solve( i+1, 0) + solve( i+1, 6);
  else if( msk == 2) ans =solve( i+1, 5);
  else if( msk == 3) ans= solve( i+1, 4);
  else if( msk ==4) ans =solve( i+1, 0) + solve( i+1, 3);
  else if( msk == 5) ans= solve( i+1, 2);
  else if( msk == 6)  ans= solve( i+1, 1);
  else if( msk == 7)ans= solve( i+1, 0);
  return ans;
}
int main(){
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif 
  while( cin >> n && n!=-1){
    memset( dp, -1, sizeof(dp));
    int ans = solve( 0, 0 );
    cout << ans <<endl;
  }
  return 0;
}
