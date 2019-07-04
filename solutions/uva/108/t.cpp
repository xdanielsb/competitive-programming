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


const int MAXN = 200;
int m[MAXN][MAXN], acum[MAXN][MAXN];

int sum( int i, int j, int m , int n){
  int ans = acum[m][n];
  if( j) ans-= acum[m][j-1];
  if( i) ans-= acum[i-1][n];
  if( i >0 &&  j >0 ) ans += acum[i-1][j-1];
  return ans;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
 int n;
 while( cin >> n){
    memset( m, 0, sizeof( m ));
    memset( acum, 0, sizeof( acum ));

    rep(i, 0, n){
      rep(j, 0, n){
        cin >> acum[i][j];
        m[i][j] = acum[i][j];
        if( i ) acum[i][j] += acum[i-1][j];
        if( j ) acum[i][j] += acum[i][j-1];
        if( i> 0 && j>0) acum[i][j] -= acum[i-1][j-1];
      }
    }

    int ans = INT_MIN;
    rep(i, 0, n){
      rep(j, 0, n){
        rep(mr, i, n){
          rep( mc, j, n){
            ans = max( ans,   sum(i,j, mr, mc));
          }
        }
      }
    }
    cout << ans <<endl;
 }
  
  
  
  
  return 0;
}
