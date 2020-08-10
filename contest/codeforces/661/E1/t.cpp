#include <bits/stdc++.h>
#define endl '\n'
#define d(x) cout <<#x << " = " << x << ", ";
#define d1( x ) d(x); cout <<endl;
#define d2( x, y ) d(x); d(y); cout <<endl;
#define d3( x, y, z ) d(x); d(y); d(z); cout <<endl;
#define F first
#define S second
#define PB push_back
#define size( x )   int( ( x ).size( ) )
#define endl '\n'
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int maxn = 2e5;
int w[maxn]; // w[i] weight of edge i
int c[maxn]; // c[i] number of paths that pass by the edge i
vector< ii > G[maxn];

void dfs( int u, int e = -1){
  if( size(G[u]) == 1){
    if (e !=-1)c[e] = 1;
  }
  for( auto [node, edge]: G[u]){
    if( edge == e) continue;
    dfs(node, edge);
    if( e!= -1)
      c[e] += c[edge];
  }
}


int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
 
  int t;
  cin >> t;
  while(t--){
    memset(w, 0, sizeof(w));
    memset(c, 0, sizeof(c));
    ll n, s, a, b;
    cin >> n >> s;
    for( int i = 0; i < n; i++) G[i].clear();
    for( int i = 0 ; i < n - 1; i++){
      cin >> a >> b >> w[i];
      a--; b--;
      G[a].push_back({b, i});
      G[b].push_back({a, i});
    }
    dfs(0);

    ll cost= 0;
    set< pair< ll, int>> sets;
    for( int i = 0; i < n-1; i++){
      cost += w[i] *1ll * c[i];
      sets.insert({ w[i]*1ll*c[i] - (w[i]/2ll)*c[i], i});
    }
    int ans = 0;

    while( cost > s){
      auto [diff, edge] = *sets.rbegin();
      sets.erase(prev(sets.end()));
      cost -= diff;
      w[edge] /= 2;
      sets.insert({w[edge]*1ll*c[edge] - (w[edge]/2ll)*c[edge], edge});
      ans++;
    }
    cout <<ans <<endl;
  }
  return 0;
}
