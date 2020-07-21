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
int n,m ;
const int maxn = 2e5 + 10;
set<int> G[maxn];
vector<int> st;
int vis[maxn];
void dfs( int src ){
  vis[src] = 1;
  for( int u: G[src]){
    if( vis[u] == 0){
      dfs(u);
    }
  }
  st.push_back( src );
}


int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin)) 
    cerr << "no file..."<<endl;
#endif
  int t;
  cin >>t ;
  int ti, from, to;
  while(t--){
    memset(vis, 0 , sizeof(vis));
    st.clear();
    for( int i = 1; i<=n; i++)
      G[i].clear();
    cin >> n >> m;
    //reading the graph
    vector< ii > edges;
    for( int i = 0; i < m; i++){
      cin >> ti >> from >> to;
      if( ti ){
        G[from].insert( to );
      }
      edges.push_back( {from, to});
    }
    // building topological sort
    for( int i = 1; i <= n; i++){
      if( vis[i] == 0)
        dfs( i );
    }

    // delete backward relations
    reverse(all(st));
    vector<int> pos(n+1);
    for( int i = 0; i < size(st); i++){
      pos[st[i]] = i;
    }
    bool isPossible = true;
    for( int src: st){
      for( int u: G[src]){
        isPossible &= pos[src] < pos[u];
      }
    }

    if(!isPossible){
      cout <<"NO\n";
    }else{
      cout <<"YES\n";
      for( ii edge: edges){
        if( pos[edge.F] < pos[edge.S]){
          cout << edge.F << " " <<edge.S;
        }else{
          cout << edge.S << " " <<edge.F;
        }
        cout << endl;
      }
    }
  }
  
  return 0;
}
