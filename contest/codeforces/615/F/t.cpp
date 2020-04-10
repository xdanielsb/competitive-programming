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
int n;
 
 
void bfs( int src, int &dst, vector<vi > &G, vi &dad){
  queue< int> q;
  vector< bool> vis(n, false);
  vector< int > dist( n, 0);
  dist[ src ]=0;
  dad[ src ] = -1;
  q.push( src ); 
  vis[src]=true;
  int  ln = -1;
  while(!q.empty()){
     int node = q.front(); q.pop();
     for( int son: G[node]){
       if( !vis[son]){
          q.push( son ); 
          vis[son] = true;
          dad[son] = node;
          dist[son] = dist[node]+1;
          if( dist[son] > ln) {
             ln = dist[son]; 
             dst = son;
          }
       }
     }
  }
}
 
int multibfs( vi &path, vector< vi >&G, int &third){
  queue<int > q;  vector< bool> vis(n, false); vi dist(n, 0);
  int bd = 0;
  for( int node : path){
      q.push( node); vis[node]=true; dist[node]= 0;
  }
  while(!q.empty()){
    int node = q.front(); q.pop();
    for( int son: G[node]){
      if( !vis[son]){
        q.push( son); 
        vis[son] = true;
        dist[son] = dist[node] +1;
        if( dist[son] > bd){
          bd = dist[son];
          third = son;
        }
      }
    } 
  }
  return bd;
}
 
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin)) 
    cerr << "no file..."<<endl;
#endif
 
  while( cin >> n){
    vector< vi > G(n); vi dad(n);
    int from, to;
    rep(i, 1, n){
      cin >> from  >> to; 
      from--; to--;
      G[from].PB(to); 
      G[to].PB(from);
    }
 
    //find diameter 
    int src = 0, dst= -1;
    bfs( src, dst, G, dad );
 
    src = dst;
    bfs( src, dst, G, dad);
    //build nodes in diameter
    vector< int > path;
    int aux = dst;
    while( aux != -1){
      path.PB( aux);
      aux = dad[aux];
    }
 
    //find third node
    
    int third = -1;
    int dis = multibfs(path, G, third);
    if( dis==0)third = path[1];
    assert( !(third == -1));
    src++; dst++;third++;
    cout << (dis + size(path) - 1) <<endl;
    cout << src << " " << dst << " " << third <<endl;
  }
  return 0;
}
