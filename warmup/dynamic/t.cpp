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
const int maxn = 300;

int ma[maxn][maxn];
int dp1[maxn][maxn];
int dp2[maxn][maxn];
int n, m;
int ite( ){
  rep(i, 1, n+1){
    rep(j, 1, m+1){
      dp1[i][j] = ma[i][j] + min(dp1[i-1][j], dp1[i][j-1]);
    }
  }
  rep(i, 1, n+1){
    rep(j, 1, m+1) cout <<dp1[i][j] << " ";
    cout <<endl;
  }
  return dp1[n][m];
}
int rec( int i =1, int j=1){
  if( i > n || j > n) return 1e9;
  if( ~dp2[i][j]) return dp2[i][j];
  if( i == n && j == m) return dp2[i][j] =   ma[n][m];
  return dp2[i][j] = ma[i][j] + min( rec(i+1, j), rec(i, j+1));
}

vector< ii > path, path2;

void rec2(int val, int i=1 , int j=1){
  val -= ma[i][j];
  path.PB(ii(i,j));
  if( dp2[i+1][j] == val) rec2(val, i+1, j);
  else if( dp2[i][j+1] == val) rec2(val, i,j+1);
}


void rec1(int val, int i , int j){
  val -= ma[i][j];
  path2.PB(ii(i,j));
  if( val == 0 ) return;
  if( dp1[i-1][j] == val) rec1(val, i-1, j);
  else rec1(val, i,j-1);
}


int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif

  memset(dp1, 0x3f, sizeof(dp1));
  memset(dp2, -1, sizeof(dp2));
  dp1[0][1] = dp1[1][0] = 0;
  while( cin >> n >> m){
    rep(i, 1, n+1) rep(j, 1, m+1) cin >> ma[i][j];

    int a1 = ite();
    int a2 = rec();
    cout <<endl;
    rep(i,1, n+1){
      rep(j, 1, m+1)cout << dp2[i][j] << " ";
      cout << endl;
    }
    rec2( a2);
    rec1(a1, n, m);
    sort(all(path)); sort(all(path2));
    cout << endl<< size(path) << endl;
    for( ii x: path)cout<< "("<< x.F << " " << x.S << "), ";
    cout << endl << size(path2) <<endl;
    for( ii x: path2)cout<< "("<< x.F << " " << x.S << "), ";

    debug2(a1, a2);
  }
  return 0;
}
