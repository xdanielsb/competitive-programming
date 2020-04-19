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
int d[MAXN]; //depth
const int L = 22;
int p[L][MAXN]; // parent i of node j
vi G[MAXN];
// source, and parent of that node
// update the depth
void dfs( int src, int prn){
   d[src] = d[prn] + 1;
   p[0][src] = prn;
   for( int &son: G[src]){
      if( son != prn){
        dfs( son, src);
      }
   }
}
//precompute table
void lca(){
  rep(i, 1 , L){
    rep(j, 0, MAXN){
      if( p[i-1][j] != -1){
        p[i][j] = p[ i-1][ p[i-1][j] ];
      }
    }
  }
}

// check if fat is an ancestor of father
bool ispar(int son, int fat){
  if(fat == 0) return true;
  if( d[fat] > d[son] ) return false;
  for( int i= L-1; i>=0; i--){
    if( d[ p[i][son]] >= d[fat])
      son = p[i][son];
  }
  /* debug2(son, fat); */
  return son == fat;
}



int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin)) 
    cerr << "no file..."<<endl;
#endif

  int n, m;
  while( cin >> n>> m){
    int from, to ;
    rep(i, 0, n)G[i].clear();
    memset(d, 0, sizeof(d));
    memset(p, -1, sizeof(d));
    rep(i, 0, n-1){
      cin >> from >> to; from--;to--;
      /* cout << from << " " << to << endl; */
      G[from].PB(to);
      G[to].PB(from);
    }
    dfs(0,0); lca();
    /* rep(i,0, n) cout << i << " " << d[i] <<" "<< p[0][i] <<endl; */
    int numNodes, node;
    rep(i, 0, m){
      cin >> numNodes;
      vi q(numNodes);
      rep(j,0,numNodes){
        cin >> q[j];q[j]--;
      }
      sort( all(q), []( int x, int y){ return d[x] < d[y];});
      int ok= true;
      for( int j = 0; j <numNodes; j++){
        bool ans= ispar(q.back(), p[0][q[j]]);
        ok &= ans;
      }
      if( ok) puts("YES");
      else puts("NO");
    }

  }
  return 0;
}
