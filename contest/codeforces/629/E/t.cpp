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

const int MAXN = 2e5 + 15;
vi G[MAXN], M[MAXN];
int p[MAXN], vis[MAXN];
unordered_set < int> s; // elements that should be in the path

bool isPossible( int src = 0){
    queue< ii >q; // {node, how_many_valid_nodes_has}
    q.push({src, 0});
    while(!q.empty()){
      ii u = q.front(); q.pop();
      /* debug2(u.F, u.S); */  
      if( s.count(u.F))  u.S++;
      if( u.S == size(s)) return true;
      for( int v: G[u.F]){
        q.push({v, u.S});
      }
    }
    return false;
}

void bfs( int src){
  queue< int > q;
  vis[src] = 1;
  q.push(src);
  while(!q.empty()){
     int u= q.front(); q.pop();
     for( int v: M[u]){
        if(!vis[v]){
          vis[v] = 1;
          G[u].PB(v);
          q.push(v);
          p[v] = u;
        }
     }
  }
}
  

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin)) 
    cerr << "no file..."<<endl;
#endif
  int n,m ;
  while( cin >> n >> m){
    int from, to;
    rep(i, 0, n) G[i].clear();
    rep(i, 0, n) M[i].clear();
    memset( p, 0, sizeof( p ));
    memset( vis, 0, sizeof( vis ));
    s.clear();
    // dad[0] = 0
    rep(i, 0, n-1){
      cin >> from >> to;from--;to--;
      M[from].PB(to);
      M[to].PB(from);
    }
    bfs(0);
    int numEdges, node;
    rep(i, 0, m){
      cin >> numEdges;
      /* debug1(numEdges); */
      s.clear();
      rep(j, 0, numEdges){
         cin >> node; node--;
         s.insert( p[node]);
      }
      bool ans =  isPossible();
      printf(ans?"YES\n":"NO\n");
    }
  }

  
  return 0;
}
