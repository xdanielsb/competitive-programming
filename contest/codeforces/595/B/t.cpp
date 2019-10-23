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

int dfs(int i, int r, vector<bool> &vis, vector< int > &g, vector< int> &parent){
  if( vis[i] ) return 0;
  vis[i] = true; parent[i] = r;
  return 1 + dfs( g[i], r, vis, g, parent);
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
 
  int q; cin >> q; int n, x;
  while( q--){
    cin >> n;
    vi A(n), dist(n), parent(n);  
    vector< bool > vis( n, false);
    rep(i, 0, n){
      cin >> x; x--;
      A[i] = x;
    }

    rep(i, 0, n){
      if( !vis[i]) dist[i] = dfs( i, i, vis, A, parent);
      cout << dist[parent[i]] << " ";
    }
    cout <<endl;

  }
  return 0;
}
