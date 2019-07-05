#include <bits/stdc++.h>
#define endl '\n'
#define debug1( x ) cout << #x << " = " <<  x << endl;
#define debug2( x, y) cout <<#x << " = " << x << " , " <<#y << " = " << y <<endl;
#define F first
#define S second
#define PB push_back
#define endl '\n'
#define rep(i, a, b) for( __typeof(a) i =(a); i<(b);i++)
#define rept(i, a, b) for( __typeof(a) i =(a); i<=(b);i++)
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;


typedef tuple< int,int,int > edge;
typedef vector < int > vi;
bool customSort(const edge &a,const edge & b){
  return get<2>(a) < get<2>(b);
}

struct union_find {
  vi p;
  union_find(int n) : p(n, -1) { }
  int find(int x) {
    return p[x] < 0 ? x : p[x] = find(p[x]);
  }
  bool unite(int x, int y) {
    int xp = find(x), yp = find(y);
    if (xp == yp) return false;
    if (p[xp] > p[yp]) swap(xp,yp);
    p[xp] += p[yp];
    p[yp] = xp; //add -1 if merge
    return true;
  }
  int size(int x) {
     return -p[find(x)];
  }
};
vector< int > mst( vector< edge > &edges , int n ){
  union_find uf( n );
  vector< int > res;
  sort( edges.begin(), edges.end(), customSort);
  int f, t , w;
  int tw =0;
  for( const edge &e: edges){
    tie(f, t, w) = e;
    if( !uf.unite( f, t ) )res.push_back(  w);
  }
  return res;
}


int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int n, m;
  int from, to, w;
  while( cin >> n>> m && m && n ){
    vector< edge > edges( m );
    rep(i, 0, m){
      cin >> from >> to >> w;
      edges[i] = make_tuple( from, to, w);
    }
    vector< int > ans = mst( edges, n );
    if( ans.size() == 0){
      cout << "forest" <<endl;
    }else{
      sort( all(ans));
      for( int i =0; i < ans.size(); i++){
         if( i > 0) cout << " ";
         cout << ans[i];
      }
      cout <<endl;
    }

  }
  
  
  
  
  return 0;
}
