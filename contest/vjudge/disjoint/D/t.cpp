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
typedef long double ld;
typedef pair<ld, ld> ii;
typedef vector<int> vi;

ld dist( ii a, ii b){
  return sqrt( (a.F-b.F)*ld(a.F-b.F) + (a.S-b.S)*(a.S-b.S));
}

struct union_find{
  vi v;
  union_find( int _n): v(_n,-1){}
  union_find(){}
  bool join( int a, int b){
    int fa = find(a ), fb = find(b );
    if( fa == fb ) return false;
    if( v[fb] > v[fa] ) swap( fa, fb);
    v[fa] += v[fb];
    v[fb] = fa;
    return true;
  }
  int find( int a){
    return v[a] < 0 ? a : v[a]  = find( v[a] );
  } 
};


int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
 
  int q, s, p; cin >> q;
  while( q--){
    cin >> s >> p;
    vector< ii > edges( p) ;
    rep( i, 0, p){
      cin >> edges[i].F >> edges[i].S;
    }
    
    vector< pair< ld, ii >> tree;
    rep(i, 0, p){
      rep(j, i+1, p){
        ld d = dist(edges[i], edges[j]);
        tree.PB( { d, {i,j}});
      }
    }
    sort( tree.rbegin(), tree.rend());
    union_find uf( p );

    sort( all( tree));
    int aux = 0;
    ld ans = 0;
    rep(i, 0, size( tree)){
      if( uf.join(tree[i].S.F, tree[i].S.S) ){
        aux++;
        ans = max( ans, tree[i].F); 
      }
      if( aux == p-s) break;
    }

    cout << setprecision( 2) << fixed << ans <<endl;
  }
  
  return 0;
}
