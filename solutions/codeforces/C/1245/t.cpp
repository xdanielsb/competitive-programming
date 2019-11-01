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
const int mod  = 1e9 +7;

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  
  string s;
  while( cin >> s ){
    int n = size ( s );
    vi dp( n+1, 0);
    ll ans = 1;
    rep(i, 0, n) if( s[i] == 'm' or s[i] == 'w') ans = 0;
    if( ans == 0){
      cout << ans <<endl;
    }else{
      dp[0] = dp[1] = 1;
      rep(i, 2, n+1){
        dp[i] = dp[i-1];
        if( s[i-2] == s[i-1] && (s[i-1] == 'u' || s[i-1] == 'n'))
          dp[i] = (dp[i-1] + dp[i-2])%mod;
      }
      cout << dp[n] <<endl;
    }
  }
  return 0;
}
