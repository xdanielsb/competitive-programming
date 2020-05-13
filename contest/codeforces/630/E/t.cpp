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
ll mod = 998244353;
ll fpow( ll b , ll e){
  ll ans = 1;
  while( e > 0 ){
    if( e & 1) ans = (ans * b ) % mod;
    b = (b * b)%mod;
    e   >>= 1;
  }
  return ans;
}
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  ll n, m, l, r;
  /* debug1(fpow(2 , 5)); */
  while( cin >> n >> m >> l >> r){
    ll diff = r - l + 1;
    if( n*m & 1){
      cout << fpow(diff, n*m) <<endl;
    }else{
      ll even = diff  >> 1, odd = diff - even;
      ll ans = ((fpow(even+odd, n*m) + fpow(even-odd, n*m))*fpow(2, mod-2)+mod)%mod;
      cout << ans << endl;

    }

  }

  return 0;
}
