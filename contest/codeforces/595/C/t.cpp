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
typedef vector<ll> vi;

vi vals;

ll p3[37];

void f( int i, int j){
  if( j > 100000 ) return;
  vals.PB( i);
  f( i + j, j*3ll);
  f( i, j*3ll);
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
 
  int q;cin >> q; int n;
  p3[0] =1; 
  for( int i= 1; i<= 37; i++) p3[i] = p3[i-1]*3ll;
  rep( i, 0, 38) debug1(p3[i]);

  f(0, 1);
  sort( all(vals));

  while( q--){
    cin >> n;
    int p = lower_bound( all( vals ),  n) - vals.begin();
    cout << vals[p ] << endl;
  }
  
  
  
  return 0;
}
