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

set<int> nums;


void bfs( int x, vector< set<int>> & g ){
  queue< int > q;
  q.push( x );

  while( !q.empty()){
    int f = q.front(); q.pop();
    set< int > d;
    for( int i: nums){
      if( !g[f].count( i)){
        d.insert( i); q.push( i );
      }
    }
    for( int i: d) nums.erase( i );
  }
} 

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int n, m;
  int from, to;
  while( cin >> n >>  m){
    vector< set< int >> g(n+1);
    rep(i, 0, m){
      cin >> from >> to;
      g[from].insert( to );
      g[to].insert( from);
    }
    nums.clear();
    rep(i, 1, n+1) nums.insert( i );
    int ans = -1;
    rep(i, 1, n+1){
      if( nums.count( i)){
        ans++;
        bfs( i, g );
        nums.erase( i );
      }
    }
    cout << ans <<endl;
  }
  return 0;
}
