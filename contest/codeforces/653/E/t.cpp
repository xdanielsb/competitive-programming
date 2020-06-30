#include <bits/stdc++.h>
#define endl '\n'
#define debug1( x ) cout << #x << " = " <<  x << endl;
#define debug2( x, y) cout <<#x << " = " << x << " , " <<#y << " = " << y <<endl;
#define debug3( x, y, z) cout <<#x << " = " << x << " , " <<#y << " = " << y << " , " <<#z << " = " << z <<endl;
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
  
  int n, k;
  while( cin >> n >> k){
    int t, a, b;
    vector<int> va, vb, both;
    for( int i = 0; i < n; i++){
      cin >> t >> a >> b;
      if( a && b ){
        both.push_back( t );
      }else if( a ){
        va.push_back( t );
      }else if( b ){
        vb.push_back( t );
      }else{
        assert(true);
      }
    }
    if( size(va) + size(both) < k || size( vb) + size(both) < k){
      cout << -1 <<endl;
    }else{
      int ans = INT_MAX;
      both.push_back(0);
      va.push_back(0);
      vb.push_back(0);
      sort( all(both));
      sort( all(va));
      sort( all(vb));
      int nbo = size(both), nb = size(vb), na = size(va);
      for( int i = 1; i < size(both); i++) both[i] += both[i-1];
      for( int i = 1; i < size(va); i++) va[i] += va[i-1];
      for( int i = 1; i < size(vb); i++) vb[i] += vb[i-1];
      for( int i = 0; i < min(k+1, nbo); i++){
        /* debug2( i, k-i); */
        if( k-i < na && k-i < nb){
          ans = min( ans, both[i] + va[k-i] + vb[k-i]);
        }
      }
      cout << ans <<endl;
    }
  }
  
  return 0;
}
