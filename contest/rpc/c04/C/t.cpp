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
const int maxn = 1e5 + 10;
vector< int> G[maxn];
bool vis[maxn];
int dis[maxn];
int bfs(){
  queue<int> q;
  int ans = 0;
  int cur = 1;
  q.push(cur);
  while(!q.empty()){
    int t  = q.front(); q.pop();
    for( int son: G[t]){
      if( son == n) return dis[t];
      if( vis[son]) continue;
      vis[son] = true;
      dis[son] = dis[t]+1;
      q.push(son);
    }
  }
  return 0;
}



int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  while(cin >>n >> m){
    for( int i = 0; i <= n; i++){
      G[i].clear();
      vis[i] = false;
      dis[i] = 0;
    }
    int from, to;
    for( int i = 0; i< m; i++){
      cin >> from >> to;
      G[from].PB(to);
      G[to].PB(from);
    }
    int ans = bfs();
    cout << ans <<endl;

  }

  return 0;
}
