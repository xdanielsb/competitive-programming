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
int n, m;
const int maxn = 2e5 +10;
vi G[maxn];
int depth[maxn], sons[maxn], deg[maxn];
int dfs(int src, int pt){
  for( int son: G[src]){
    if( son == pt) continue;
    depth[son] = depth[src]+1;
    sons[src] += dfs(son, src) +1;
  }
  return sons[src];
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  while( cin >> n >> m){
    /* debug2(n,m); */
    int from, to;
    memset(deg, 0, sizeof(deg));
    memset(sons, 0, sizeof(sons));
    memset(depth, 0, sizeof(depth));
    rep(i, 0, n) G[i].clear();
    rep(i, 0, n-1){
      cin >> from >> to ;
      from--; to--;
      G[from].PB(to);
      G[to].PB(from);
      deg[from]++;
      deg[to]++;
    }
    dfs(0,0);
    priority_queue<ii> pq;
    rep(i, 0, n){
      /* debug2(depth[i], sons[i]); */
      if(deg[i]==1)
        pq.push(ii(depth[i]-sons[i], i));
    }
    ll ans = 0;
    rep(i, 0, m){
      ii t = pq.top(); pq.pop();
      /* debug1(ans); */
      for( int son: G[t.S]){
        deg[son]--;
        if( deg[son] == 1){
          pq.push(ii(depth[son]-sons[son], son));
        }
      }
      ans += t.F;
    }
    cout << ans <<endl;
  }
  return 0;
}
