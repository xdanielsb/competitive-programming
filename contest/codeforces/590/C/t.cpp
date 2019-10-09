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

bool isPossible( vector< vi > &A, int n, int r, int c){
  int x = A[r][c];
  if( c == n) return r == 1;
  if( !x) return isPossible( A, n, r, c+1);
  if( r == 0){
    if( A[1][c] ) return isPossible( A, n, 1, c+1);
  }else{
    if( A[0][c] ) return isPossible(A, n, 0, c+1);
  }
  return false;
}

int main(){
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int n;
  int q; cin >>q;
  while ( q--){
    cin >> n;
    vector< vi > A(2);
    char x;
    rep(i, 0, 2){
      rep( j, 0, n){
        cin >> x;
        int var =  x-'0';
        A[i].PB( var > 2 );
      }
    }
    bool ok = isPossible( A, n, 0,0);
    printf( ok?"YES":"NO"); cout << endl;
  }
  
  return 0;
}
