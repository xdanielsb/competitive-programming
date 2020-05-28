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
const int maxn = 60;
int ma[maxn][maxn];

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif

  int t;
  cin >> t;
  /* int ca = 1; */
  while(t--){
    int n, m, a , b;
    cin >> n >> m >> a >> b;
    /* if( ca == 807){ */
    /* cout << n<< "-"<< m << "-" << a <<  "-" <<b<<endl; */
    /* } */
    /* ca++; */

    bool isPossible = true;
    for( int rot = 0; rot <=m; rot++){
      isPossible = true;
      memset(ma, 0, sizeof(ma));
      vi col(m, b); // each col can have b elements
      int shift = 0;
      for( int r = 0; r < n && isPossible; r++){
        int auxa = a;
        for( int c = 0; c < m && auxa; c++){
          if( col[(shift+c)%m]){
            col[(shift+c)%m]--;
            auxa--;
            ma[r][(shift+c)%m]++;
          }
        }
        shift+=rot;
        if( auxa > 0){
          isPossible = false;
        }
      }
      rep(i, 0, m)isPossible &= col[i] == 0;
      if( isPossible) break;
    }
    if( !isPossible){
      cout << "NO\n";
      continue;
    }
    cout <<"YES\n";
    rep(i, 0, n){
      rep(j, 0, m){
        cout << ma[i][j];
      }
      cout <<endl;
    }

  }
  return 0;
}
