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
const int maxn = 304;
int m[maxn][maxn];
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
    int nrows, ncols,x ;
    bool ok = true;
    cin >> nrows >> ncols;
    for( int i = 0; i < nrows; i++){
      for( int j = 0; j < ncols; j++){
        cin >> x;
        if( (i==0 && j==0) || (i==0 && j==ncols-1) || (i==nrows-1 && j==0) || (i==nrows-1 && j==ncols-1))
          m[i][j] = 2;
        else if( i== 0 || i == nrows-1 || j == 0 || j ==ncols-1)
          m[i][j] = 3;
        else
          m[i][j] = 4;
        if( x > m[i][j]) ok = false;
      }
    }
    if( ok ){
      cout << "YES\n";
      for( int i = 0; i < nrows; i++){
        for( int j = 0; j  < ncols; j++){
          cout <<m[i][j]<< " ";
        }
        cout <<endl;
      }
    }else{
      cout<< "NO\n";
    }
  }
  
  return 0;
}
