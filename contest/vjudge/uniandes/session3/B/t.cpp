#include <iostream>
#include<string.h>
#define endl '\n'
#define debug1( x ) cout << #x << " = " <<  x << endl;
#define debug2( x, y) cout <<#x << " = " << x << " , " <<#y << " = " << y <<endl;
#define F first
#define S second
#define PB push_back
#define size( x )   int( ( x ).size( ) )
#define endl '\n'
#define rep(i, a, b) for( __typeof(a) i =(a); i<(b);i++)
#define rept(i, a, b) for( __typeof(a) i =(a); i<=(b);i++)
#define all(x) x.begin(),x.end()

using namespace std;

int m[105][105];
int dp[105][105];
int rows;
int dfs(int r, int c){
  if( c < 0) return 0;
  if( r >= rows) return 0;
  if( dp[r][c] != -1) return dp[r][c];
  return dp[r][c]= m[r][c] + max( dfs(r+1, c), dfs(r+1, c+1));
}

int main(){
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  while( cin >> rows){
    memset( dp, -1, sizeof( dp));
    rep(i, 0, rows) rep(j, 0, i+1) cin >> m[i][j];
    int  res = dfs(0,0);
    cout << res <<endl;
  }
  return 0;
}
