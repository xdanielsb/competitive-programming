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
  while( t--){
    ll l, r, m;
    cin >> l >> r >> m;
    for( int a = l ; a <= r; a++){
      ll u = ( m / a ) * a ;
      ll v = u +a ;
      if ( u / a >= 1 && m - u <= r - l ){
        cout << a << " " << l + m - u<< " " << l << "\n";
        break;
      }
      else if( v /a >= 1 && v -m <=r - l){
        cout << a << " " << l << " " << l + v -m << "\n";
        break;
      }
    }
  }
  
  return 0;
}
