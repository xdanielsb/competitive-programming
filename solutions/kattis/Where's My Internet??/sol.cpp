/**
 *    author:  xdanielsb
 *    created: 2018-07-17
**/
#include<bits/stdc++.h>
#define debug(x) cout << #x <<  "  = " << x <<endl;
#define MAX 200005
using namespace std;

int arr[MAX];

void init( int N){
  for( int i=1; i<= N; i++) arr[i] = -1;
}

void printa( int N){
  for( int i=1; i<= N; i++) cout << arr[i] << " ";
  cout <<endl;
}
int find( int a){
  return  arr[a] < 0? a: arr[a] = find( arr[a] ); 
}

bool unite(int a, int b){
  int xa = find(a), ya = find(b);
  if ( xa == ya) return false;
  if( arr[xa] > arr[ya]) swap(xa, ya);
  arr[xa] += arr[ya];
  arr[ya] = xa;
  return true;
}

int main(){
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif

  int N, M;
  int from, to;
  cin >> N >> M;
  init( N );
  for( int i = 0; i < M; i++){
    cin >> from >> to;
    unite( from, to );
  }
  int res = 0; 
  for( int i = 1 ; i<= N; i++){
    int aux = find( i );
    /* debug(aux); debug ( i ); */
    if ( find(1) != aux ){
        res++;
        cout << i <<endl;
    }
  }
  if( res == 0) {
    cout << "Connected" <<endl;
  }
  return 0;
}
