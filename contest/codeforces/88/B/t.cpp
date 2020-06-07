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

const int maxn = 1000+5;
char ma[maxn][maxn];
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif

  int t;
  cin >> t;
  while(t--){
    memset(ma, '#', sizeof(ma));
    // a is cost of 1x1
    // b is cost of 1x2
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    for( int r = 1; r <= n; r++){
      for( int c = 1; c <= m; c++){
        cin >> ma[r][c];
      }
    }
    ll ans = 0;
    for( int r = 1; r <= n; r++){
      for( int c = 1; c <= m; c++){
        if( ma[r][c] == '.' && ma[r][c+1] == '.' && (c+1 <= m ) && (b < 2*a)){
          ans += b;
          ma[r][c] = ma[r][c+1] = '@';
        }
        else if( ma[r][c] == '.' ){
          ans+= a;
          ma[r][c] = '@';
        }
      }
    }

    cout << ans <<endl;
  }


  return 0;
}
