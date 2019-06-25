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

const int MAXN = 100;
int ma[MAXN][MAXN];
int row[2][MAXN];
int col[2][MAXN];
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  ll n,m;
  while( cin >> n>> m){
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    ll ans = -n*m;
    rep(i, 0, n) rep(j, 0, m){
      cin >> ma[i][j];
      row[ ma[i][j]][i]++;
      col[ ma[i][j]][j]++;
    }
    rep(i, 0, n) rep(j, 0, 2)ans += (1ll << row[j][i])-1;
    rep(i, 0, m) rep(j, 0, 2)ans += (1ll << col[j][i])-1;
    cout << ans <<endl;
  }
  return 0;
}
