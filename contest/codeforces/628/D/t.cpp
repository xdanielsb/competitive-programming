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

  ll u, v;
  while( cin >> u >> v ){

    // u + b = u xor b + 2 (u & b)
    if( u > v || u%2!=v%2){
      cout << -1 << endl;
      continue;
    }
    if( u==v && u == 0){
      cout << 0 <<endl;
      continue;
    }
    if( u==v ){
      cout << 1 << endl;
      cout << u <<endl;
      continue;
    }
    ll x = (v-u)/2;
    if ( u&x){
      cout <<  3 << endl;
      cout << u << " " << x << " " <<x <<endl;
    }else{
      // if u & x == 0 then
      // u + x == u xor x then
      // u +x +x = v -> u + 2x = v then
      // x = (v-u)/2
      cout << 2 <<endl;
      cout << (u+x) << " " << x <<endl;
    }

  }
  return 0;
}
