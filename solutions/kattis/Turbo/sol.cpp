/**
 *    author:  xdanielsb
 *    created: 2018-12-11
**/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int arr[ MAXN ];
int n;
int Tree[ MAXN*2];
void built( ){
  for ( int i =0; i < n; i++)
    Tree[i+n] = 1;
  // built the tree
  for( int i = n-1; i> 0; i--)
    Tree[i] = Tree[i<<1] + Tree[i<<1|1];
}

int query( int l , int r){
  l+= n; r+=n;
  int res = 0;
  for(; l < r;  l >>= 1, r >>=1){
    if( l&1) res+= Tree[ l++ ];
    if( r&1) res+= Tree[--r];
  }
  return res;
}

void update( int pos, int val){
  pos += n;
  Tree[ pos ] = val;
  for( int i = pos; i > 1; i>>=1){
    Tree[ i>>1 ] = Tree[i] + Tree[ i ^ 1];
  }
}

int main(){
#ifdef LOCAL 
  freopen("in","r", stdin);
#endif
  int  aux;
  while( cin >> n){
    memset( arr, 0, sizeof( arr ) );
    for( int i= 0; i< n; i++){
      cin >> aux;
      aux--;
      arr[ aux ] = i; 
    }
    vector< int> A( n, 1);
    int sum = 0;
    int ini = 0, end = n-1;
    built();
    for( int i = 1 ; ini <= end ; i++){
      sum = 0;
      if( i&1 ){
          update( arr[ ini ], 0);
          sum = query(0, arr[ini]);
          ini++;
      }else{
          update( arr[ end ], 0 );
          sum = query(0, n) - query( 0, arr[end]);
          end--;
      }
      cout << sum <<endl;
    }
   }
  return 0;
}
