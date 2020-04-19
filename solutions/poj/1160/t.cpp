#include <iostream>
#include <string.h>
#define endl '\n'
#define rep(i, a, b) for( __typeof(a) i =(a); i<(b);i++)

using namespace std;

const int MAXN = 300 + 5;
int a[MAXN];
int dis[MAXN][MAXN], dp[MAXN][MAXN];
int main(){
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
 
  
  int n, p; // #ville,#posts
  while( cin >> n >> p){
    memset(dp, 0x3f, sizeof(dp));
    rep(i, 0, n) dp[i][i] = 0;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n)
      rep(j,i+1, n) 
         dis[i][j] = dis[i][j-1] + a[j] - a[(j+i)/2];
    rep(i, 0, n) dp[i][0] = dis[0][i];
    rep(j, 1, p)
      rep(i, j+1, n)
        rep(k, j-1, i)
          dp[i][j] = min(dp[i][j], dp[k][j-1] + dis[k+1][i]);
    
    cout << dp[n-1][p-1] << endl;
  }
  return 0;
}
