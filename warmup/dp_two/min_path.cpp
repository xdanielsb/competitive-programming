#include <bits/stdc++.h>
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
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int maxn = 100;

int n,m; //n rows, m cols
int ma[maxn][maxn];
int dp[maxn][maxn];
int dp2[2][maxn];
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  while( cin >>n >> m){
    for( int r = 1; r <= n; r++){
      for( int c = 1; c <=m; c++){
        cin >> ma[r][c];
      }
    }
    memset(dp, 0x3f3f3f, sizeof(dp));


    dp[1][0] = 0;
    for( int r = 1; r <=n; r++){
      for( int c = 1; c<=m ; c++){
        dp[r][c] = min(dp[r-1][c], dp[r][c-1]) + ma[r][c];
      }
    }
    cout << dp[n][m] << endl;


    memset(dp2, 0x3f, sizeof(dp2));
    // take care with  dp[1][0] you cannot do that here, because your dp2 memo will
    // fail, instead you need to check for that condition inside
    // fails because r&1 will reuse that initial value, after the first usage that should be
    // set to big value
    for( int r = 1; r <=n; r++){
      for( int c = 1; c<=m ; c++){
        if( r == 1 && c ==1)
          dp2[r][c] = ma[r][c];
        else
          dp2[r&1][c] = min(dp2[(r-1)&1][c], dp2[r&1][c-1]) + ma[r][c];
      }
    }
    cout <<dp2[n&1][m] <<endl;
  }




  return 0;
}
