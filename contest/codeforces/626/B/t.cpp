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

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin)) 
    cerr << "no file..."<<endl;
#endif
  int n, m, k;
  while( cin >> n >> m >> k){
    int acum = 0, x;
    vector< int > col(n+1), row(m+1);
    for( int i = 0; i <= n; i++){
      if( i < n) cin >> x;
      if( (x == 0 && acum> 0) || (acum >0  && i == n) ) {
        for( int j = 1; j<= acum; j++){
          col[j] += (acum - j + 1);
        }
        acum=0;
      }
      if( x > 0 ) acum++;
    }
    acum  =0 ;
    for( int i = 0; i <= m; i++){
      if( i < m) cin >> x;
      if( (x == 0 && acum> 0) || (acum >0  && i == m) ) {
        for( int j = 1; j<= acum; j++){
          row[j] += (acum - j + 1);
        }
        acum = 0;
      }
      if( x > 0 ) acum++;
    }
    /* for( int i = 0; i <= n; i++) debug1(col[i]); */
    /* for( int i = 0; i <= m; i++) debug1(row[i]); */
    
    ll ans =0;
    /* debug2(n,m); */
    for( int i = 1; i <= n; i++){
      if( k % i == 0){
        if( k / i <= m ){
          /* debug2( col[i], row[k/i]); */
          ans += col[i] * row[k/i];
        }
      }
    }
    cout << ans <<endl;
  }
  
  return 0;
}
