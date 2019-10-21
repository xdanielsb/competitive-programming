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


struct union_find {
  vi v;
  union_find( int _n): v(_n,-1){}
  bool unite( int a , int b){
    int xa = parent( a);
    int xb = parent( b);
    if( xa == xb ) return false;
    if( v[xb] > v[xa] ) swap( xb, xa);
    v[xa] += v[xb];
    v[xb] = xa;
    return true;
  }
  int parent( int a ){
    if( v[a] < 0)   return a;
    return  parent( v[a]);
  }
  int size( int b ){
    return -v[ parent(b) ] ;
  }
};

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  
  int q, n; cin >> q;
  string p1, p2;
  int counter ;
  while( q--){
    cin >> n ;
    union_find uf( n*2 );
    counter = 0;
    map<string, int > hash;
    rep( i, 0, n){
      cin >> p1 >> p2;
      if( hash.count( p1 ) == 0 ) hash[ p1] = counter++;
      if( hash.count( p2 ) == 0) hash[ p2] = counter++;
      uf.unite( hash[p1], hash[p2]);
      int res = uf.size( hash[p1]);
      cout <<res <<endl;
    }
  }
  
  return 0;
}
