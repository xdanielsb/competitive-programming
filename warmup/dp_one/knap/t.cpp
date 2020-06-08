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
const int maxn = 1000;
int w[maxn];
const int maxW = 1000;
int dp[maxn][maxW];

int n;
int knap(int i, int left){
  if( i == n) return 0;
  int &ans = dp[i][left];
  if(~ans) return dp[i][left];
  ans = knap(i+1, left);
  if( w[i] <= left)
    ans = max( ans,1+ knap(i+1, left - w[i]));
  return ans;
}
vi vans;
void build(int i, int left){
  if( i == n) return ;
  if( left <= 0) return;
  if( dp[i][left] == dp[i+1][left]){
    build(i+1, left);
  }else if( dp[i][left] == 1+dp[i+1][left]){
    vans.PB(w[i]);
    build(i+1, left-w[i]);
  }
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  while( cin >>n ){
    rep(i,0 , n) cin >> w[i];
    rep(i,0, n) cout << w[i] << " ";cout <<endl;
    memset(dp, -1, sizeof(dp));
    int W = 20;
    int ans = knap(0, W);

    rep(i,0 ,n){
      rep(j, 0, W+1){
        cout << dp[i][j] << " ";
      }
      cout <<endl;
    }
    debug1(ans);
    build( 0, W);
    cout << "weights" <<endl;
    for( int wi: vans)
      cout << wi << " "; cout << endl;

    return 0;
  }
}
