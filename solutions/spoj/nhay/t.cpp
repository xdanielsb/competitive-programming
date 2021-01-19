#include <bits/stdc++.h>
#define endl '\n'
#define d(x) cout <<#x << " = " << x << ", ";
#define d1( x ) d(x); cout <<endl;
#define d2( x, y ) d(x); d(y); cout <<endl;
#define d3( x, y, z ) d(x); d(y); d(z); cout <<endl;
#define F first
#define S second
#define PB push_back
#define size( x )   int( ( x ).size( ) )
#define endl '\n'
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const ll mod = 1e9+ 9;

ll power(ll x, ll y) { 
    if (y == 0)  return 1; 
    ll p = power(x, y / 2) % mod; 
    p = (p * p) % mod; 
    return (y % 2 == 0) ? p : (x * p) % mod; 
} 

struct Phash {
  string s;
  int n;
  vi dp;
  vi inv;
  Phash( string _s): s(_s), n(size(_s)) {
    ll hash = 0, pow = 1ll;
    for( int i = 0; i < n; i++){
      hash = (hash + (s[i]-'a')*pow) % mod;
      hash = (hash+mod)%mod;
      pow = (pow * 31) % mod;
      inv.emplace_back(power(pow, mod-2));
      dp.emplace_back(hash);
    }
  }

  ll hash( int l , int r){
    ll res = dp[r];
    if( l > 0 ) res = (res - dp[l-1] + mod)%mod;
    res  = (res * inv[l]) % mod;
    return res;
  }
};

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int n;
  string needle, hay;
  int test = 0;
  while( cin >> n){
    cin >> needle >> hay;
    if( test) cout <<endl;

    test++;
    Phash h1(needle), h2(hay);
    ll hneedle = h1.hash(0, size(needle)-1) ;
    /* d2(needle, hneedle); */
    for( int l = 0, r =size(needle)-1; r < size(hay) ;l++,r++){
      /* d3(l,r, h2.hash(l,r)); */
      if( hneedle == h2.hash(l, r)){
        cout << l << endl;
      }
    }
  }
  return 0;
}
