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

void bfs( int st, vector<vi> &G, int n){
  vector< int > ans, ans2;
  queue< int > q;
  q.push( st );
  vector<int> dist( n);
  vector<bool > vis(n, false);
  dist[st] = 0;
  vis[st] = true;
  while( !q.empty()){
    int t = q.front(); q.pop();
    if( dist[t]%2 ==0 ){
      ans.push_back( t+1 );
    }else{
      ans2.push_back( t+1);
    }
    for( int son: G[t]){
      dist[son] = dist[t] +1 ;
      if( !vis[son]){
        vis[son]  = true;
        q.push( son);
      }
    }
  }
  if( size(ans) < size(ans2)){
    cout << size(ans) <<endl;
    for( int x: ans) cout << x<< " "; cout <<endl;
  }else{
    cout << size(ans2) <<endl;
    for( int x: ans2) cout << x<< " "; cout <<endl;
  }

}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif


  int n, m, t;cin >>t;
  while(t--){
    cin >> n >> m;
    vector< vi > G(n);
    int to ,from;

    rep( i, 0, m){
      cin >> to >> from; to--; from--;
      G[ from ].PB( to );
      G[ to ].PB( from );
    }

    bfs( 0, G, n);


  }


  return 0;
}
