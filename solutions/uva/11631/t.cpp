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
struct union_find{
  vi v;
  union_find( int n): v(n, -1) {}
  union_find(){}

  bool unite(int a, int b){
    int fa = find(a), fb = find( b );
    if( fa == fb ) return false;
    if( v[fb] > v[fa] ) swap( fa, fb);
    v[fa] += v[fb];
    v[fb] = fa;
    return true;
  }
  int find( int a){
    return v[a] < 0 ? a: v[a] = find( v[a] );
  }

};
bool customSort( pair<int, ii> &a, pair<int, ii>  &b){
  return a.S.S < b.S.S;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int n, e;
  while( cin >> n >> e && n && e){
    int total = 0; 
    vector< pair< int, ii >> edges(e);
    rep(i, 0, e ){
      cin >> edges[i].F >> edges[i].S.F >> edges[i].S.S;
      total += edges[i].S.S;
    }
    sort( all(edges), customSort);
    union_find uf( n );

    int minGood = 0; 
    rep(i, 0, e){
      if( uf.unite( edges[i].S.F, edges[i].F ) ){
        minGood += edges[i].S.S;
      } 
    }
    cout << total-minGood <<endl;;
  }
  return 0;
}
