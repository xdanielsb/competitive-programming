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

const int maxn = 500 + 5;
int arr[maxn];
int dp[maxn][maxn];
int dp2[maxn];

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif

  int n;
  while(cin >> n){
    rep(i, 0, n) cin >> arr[i];
    memset(dp, -1, sizeof(dp));

    for( int i = 0; i < n ; i++) dp[i][i] = arr[i];
    for(int s = 2; s <= n; s++){
      for( int i = 0; i < n - s + 1; i++){
        int j = i + s - 1;
        for( int k = i; k < j; k++){
          if( dp[i][k] != -1 && dp[i][k] == dp[k+1][j])
            dp[i][j] = dp[i][k]+1;
        }
      }
    }
    for( int i = 0; i < n ; i++) dp2[i] = i + 1;
    for( int i = 0; i < n ; i++){
      for( int j = 0; j <= i; j++){
        if(dp[j][i] != -1){
          if( j == 0 ) dp2[i] = 1;
          else dp2[i] = min(dp2[i], dp2[j-1]+1);
        }
      }
    }
    cout << dp2[n-1] <<endl;

  }
  return 0;
}
