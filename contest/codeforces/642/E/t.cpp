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

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    int ones = 0, best=0;
    char x;
    vi dp(n);
    rep(i ,0 ,n){
      cin >> x;
      ones += x-'0';
      dp[i] = x-'0';
      if( i >= k){
        dp[i] = max(dp[i], dp[i-k] -1 +2 * (x-'0'));
      }
      best = max(best, dp[i]);
    }
    cout << (ones-best) << endl;
  }

  return 0;
}
