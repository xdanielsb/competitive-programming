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

const int MAXN = 105;
char ma[MAXN][MAXN];
int row[MAXN][MAXN];
int col[MAXN][MAXN];
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  int n, m;
  while( cin >> n>>m){
    memset( row, 0, sizeof(row));
    memset( col, 0, sizeof(col));
    rep(i, 0,n){
      rep(j, 0, m){
        cin >> ma[i][j];
        int aux = ma[i][j] - 'a';
        row[aux][i]++;
        col[aux][j]++;
      }
    }
    rep(i, 0, n){
      rep(j, 0, m){
        int aux = ma[i][j] -'a';
        if( row[aux][i] == 1 && col[aux][j]==1){
          cout << ma[i][j];
        }
      }
    }
    cout <<endl;
  }
  return 0;
}
