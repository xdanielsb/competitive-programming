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

const int maxn = 100;
int ma[maxn][maxn];
bool row[maxn], col[maxn];

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin)) 
    cerr << "no file..."<<endl;
#endif
  int t;
  cin >> t;
  while( t--){
    int n, m;
    cin >> n >> m;
    for( int i = 0; i< n ;i++) row[i] = true;
    for( int j = 0; j< m; j++) col[j] = true;
    for( int i = 0; i < n; i++){
      for( int j = 0; j < m ;j++){
        cin >> ma[i][j];
        if( ma[i][j]){
          row[i] = col[j] = false;
        }
      }
    }
    int w = 1;
    for( int i = 0; i < n; i++){
      for( int j = 0; j < m; j++){
        if( row[i] && col[j]) {
          row[i] = col[j] = false;
          w ^= 1;
        }
      }
    }
    printf(w?"Vivek\n":"Ashish\n");
  }
  return 0;
}
