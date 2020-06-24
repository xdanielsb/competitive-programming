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
const int maxn = 5e5+10;
vector< int> G[maxn];
vector< int> color[maxn];
int pos[maxn];
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin)) 
    cerr << "no file..."<<endl;
#endif
  int n, m, c;
  while( cin >> n >> m){
    for( int i = 0; i <= n; i++){
      G[i].clear();
      color[i].clear();
    }

    int from, to;
    for( int i = 0; i < m; i++){
      cin >> from >> to;
      G[from].PB(to);
      G[to].PB(from);
    }
    bool ok = true;
    for( int i = 1; i <= n; i++){
      cin >> c;
      if( c > n){
        ok = false;
      }
      color[c].PB(i);
    }
    
    vector< int > ord;
    vector< int> ans(n+1), last(n+1);
    for( int i = 1; i <= n && ok; i++){
      for( int u: color[i]){
        for( int son: G[u]){
          last[ans[son]] = u;
        }
        ans[u] = 1;
        while( last[ans[u]] == u) ans[u]++;
        if( ans[u] != i){
          ok =false;
        }
        ord.push_back( u);
      }
    }
    if( ok ){
      for( int x: ord) cout << x << " ";
      cout <<endl;
    }else{
      cout << -1 <<endl;
    }
  }
  
  return 0;
}
