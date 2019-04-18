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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;


ll mod = 1e9+7;


ll m( ll x){
  return (x%mod + mod)%mod;
}
ll sum( ll n ){
  ll todd, teve;
  todd = teve = 0;
  bool st = 1;
  ll cur = 1;
  //debug1( n);
  while( n > 0){
    if (st){
      todd += min(cur, n);
    }else{
      teve += min( cur, n);
    }
    st =!st;
    n-= cur;
    cur *= 2ll;
  }
  // sum of even + sum of odd
  teve %= mod;
  todd %= mod;
  ll ans = m(teve*(teve+1));
  ans = m(ans+ todd*todd);
  return ans % mod;

}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  ll l ,r ;
  while( cin >> l >> r){
    ll ans= ((sum(r)-sum(l-1))+mod)%mod;
    cout << ans <<endl;
  }




  return 0;
}
