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
typedef pair<ll,ll> ii;
typedef vector<int> vi;



int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  ll a, b;
  ll c, d;
  // b + xa = n
  // d + yc = m
  // b-d = yc - xa
  while( cin >> a >> b >>c >> d){
    bool ok = false;
    rep( i, 0, 10000){
      ll n = b + a*i;
      ll y = (n - d)/c;
      if( y >= 0  && (y*c+d) == n){
        cout << (y*c+d) <<endl;
        ok = true;
        break;
      }
    }
    if( !ok ){
      cout << -1 <<endl;
    }
  }



  return 0;
}
