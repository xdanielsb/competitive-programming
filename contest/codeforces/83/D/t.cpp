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
const int maxn = 2e5+10;
ll mod = 998244353;
ll fact[maxn];


ll fpow( ll b, ll e){
  ll ans =1ll;
  while( e > 0){
    if( e & 1) {
      ans = (ans * b)%mod;
    }
    b = (b * b)%mod;
    e >>= 1ll;
  }
  return ans;
}


ll inv(ll a, ll b){
  ll y =0;
  ll x =1;
  ll xx =0;
  ll yy =1;
  while(b){
    ll q = a / b;
    ll t = b;
    b = a%b;
    a = t;

    t = xx;
    xx = x-q*xx;
    x = t;

    t = yy;
    yy = y -q*yy;
    y = t;
  }
  if( x < 0 ) x = x +mod;
  return x;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif

  fact[0] = 1;
  rep(i, 1, maxn){
    fact[i] = (fact[i-1] * 1ll * i)%mod;
  }

  int n, m;
  while( cin >>n >> m){
    ll ans = (fact[m] * 1ll * inv(fact[n-1], mod)) % mod;
    ans = (ans * 1ll * inv(fact[m-n+1], mod)) % mod;
    ans = ( ans * 1ll * (n-2) +mod)%mod;
    ans = (ans * fpow(2ll, n-3))%mod;
    cout << ans <<endl;
  }

  return 0;
}
