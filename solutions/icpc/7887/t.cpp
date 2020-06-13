#include <bits/stdc++.h>
#define endl '\n'
#define debug1( x ) cout << #x << " = " <<  x << endl;
#define debug2( x, y) cout <<#x << " = " << x << " , " <<#y << " = " << y <<endl;
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

int n, m, a, b;

const int maxn = 1e5 +10;
vi G[maxn];
bool is[maxn]; // check if a node is in the solution
int deg[maxn];

set< ii > ans;

bool process( int id, int d){
  bool change = false;
  if( d < a || (size(ans) - d -1 < b)){
    ans.erase({deg[id], id});
    change = true;
    is[id] = false;
    for( int son: G[id]){
      if( is[son]){
        ans.erase({deg[son], son});
        deg[son]--;
        ans.insert({deg[son], son});
      }
    }
  }
  return change;
}

// the idea is take the one with the greater 
// and less degree in each iteration, because
// them are the prone to be invalid
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  while( cin >> n >> m >> a >> b){
    for( int i = 1; i <= n; i++){
      G[i].clear();
      is[i] = true;
      deg[i] = 0;
    }
    ans.clear();
    int from, to;
    for( int i = 0; i < m ; i++){
      cin >> from >> to;
      G[from].PB(to);
      G[to].PB(from);
      deg[from]++;
      deg[to]++;
    }
    for( int i = 1; i <= n; i++)
      ans.insert({deg[i], i });

    bool change = true; // check if there was a change in the last iteration
    while( change && !ans.empty()){
      ii t1 = *(ans.begin());
      int id = t1.S, d = t1.F;
      change = process(id, d);
      if( size(ans)){
        ii t2 = *(ans.rbegin());
        id = t2.S;
        d = t2.F;
        change |= process(id, d);
      }
    }
    cout << size(ans) <<endl;
  }

  return 0;
}
