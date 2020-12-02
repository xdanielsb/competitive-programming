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

const int mod = (int) ( 1e9 + 7);


int modpow( ll b, ll e){
  ll ans = 1;
  while( e > 0  ){
    if( e % 2){
      ans = (ans *1ll* b) % mod;
      e--;
    }else{
      b  = (b * 1ll * b) % mod;
      e /= 2;
    }
  }
  return ans;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  
  
  ll n, m;
  while( cin >> n >> m ){
    ll ans = 1;
    ans = modpow( 2ll, m);
    ans = (ans-1+mod)%mod;
    ans = modpow( ans, n );
    cout << ans <<endl;
  }
  return 0;
}
