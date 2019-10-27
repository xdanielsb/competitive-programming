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
  freopen("in", "r" , stdin);
#endif
 
  
  ll n, m, x;
  int q; cin >> q;
  while( q--){
    cin >> n >> m; x = m;
    vector< int > v;
    v.PB( m%10);
    x =(x + m) ;
    while( v[0] != (x % 10) ){
      v.PB( x % 10 );
      x = (x + m);
    }
    ll totald = n / m;
    //debug2(totald, size( v));
    ll each = totald / size(v);
    ll ans =0;
    rep(i, 0, size( v )){
      ans += v[i]*each;
    }
    rep(i, 0, totald % size(v) ){
      ans += v[i];
    }
    cout << ans <<endl;
  }
  
  
  return 0;
}
