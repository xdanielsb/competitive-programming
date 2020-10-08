#include<bits/stdc++.h>
using namespace std;

typedef vector < int > vi;

vector < vi > createGraph( const vi &arr){
   int n = arr.size();
   vector < vi > g( n );
   map< int, int > vis;
   for( int i = 0; i < n; i++){
     if( i ) g[ i ].push_back( i - 1);
     if( n - i -1 > 0) g[i].push_back( i + 1);
     if( vis.count( arr[ i ] ) ) 
       g[ vis[ arr[ i ] ] ].push_back(  i  );
     else
       vis[ arr[i] ] = i;
   }
   return g;
}

int utilGetMinSteps( const vector < vi > &g, int n){
  queue < int > q;
  vector< bool > vis( n, false);
  q.push ( 0 );
  vis[ 0 ] = true;
  bool isFound = false;
  vector < int > dis( n, 0);
  dis[ 0 ] = 0;
  while( !q.empty() && !isFound){
    int src = q.front(); q.pop();
    if( src == n-1){
      isFound = true; continue;
    }
    for( int son: g[ src ]){
      if( !vis[son]){
        dis[son] = dis[ src ] + 1;
        q.push( son);
        vis[son] = true;
      }
    }
  }
  return dis[ n -1 ];
}

int getMinSteps( const vi &arr ){
  vector< vi > g = createGraph( arr );
  int ans = utilGetMinSteps( g, arr.size() );
  return ans;
}

int main(){
  const vi arr =  {1,2,2,3};
  int ans = getMinSteps( arr );
  cout << ans <<endl;
  return 0;
}
