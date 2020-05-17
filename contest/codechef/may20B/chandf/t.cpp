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

int k = 0;
ll x, y ,l , r, optimal_z, result;

ll f( ll z){
  return (x&z) * ( y&z);
}

void update_ans(ll z) {
  if( !( z>= l && z<=r)) return;
  ll cur = f(z);
  if (cur > result || (cur == result && z < optimal_z)) {
    optimal_z = z;
    result = cur;
  }
}



ll solve( ){
  optimal_z = r;
  result = f(optimal_z);
  update_ans(l);
  bool is_less = false;
  ll bits_or = (x | y);

  for (ll i = 42; i >= 0; --i) {
    ll p = (1ll << i);
    if ((r & p) && (is_less || !(l & p))) {
      ll cur = 0;
      for (ll k = 42; k > i; --k) {
        ll p = (1ll << k);
        if (r & p)
          cur |= p;
      }
      bool is_bigger = is_less;
      for (ll k = i - 1; k >= 0; --k) {
        ll p = (1ll << k);
        if (!(l & p)) {
          if (bits_or & p) {
            cur |= p;
            is_bigger = true;
          }
        } else {
          if (!is_bigger || (bits_or & p))
            cur |= p;
        }
      }
      update_ans(cur);
      is_less = true;
    }
  }
  return optimal_z;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif

  int t; cin >> t;
  while(t--){
    cin >> x >> y >> l >> r;
    ll ans = solve();
    cout << ans <<endl;
  }


  return 0;
}
