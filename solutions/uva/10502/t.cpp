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

int m[105][105];

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  int rows, cols; char x;
  while( cin >> rows >> cols && rows ){
    rep(i, 0,rows) rep(j, 0, cols){ 
      cin >> x;
      m[i][j] = x -'0';
    }
    int ans =0;
    rep( i ,0 ,rows){
      rep( j , 0, cols){
        vector<int> sumc(cols);
        rep( r, i, rows){
          int sum = 0;
          rep( c, j, cols){
            sumc[c] = m[r][c] ? sumc[c]+1: 0;
            sum += sumc[c];
            int mul = (c-j+1)*(r-i+1);
            if( sum == mul) {
              ans++;
            }
          }
        }
      }
    }
    cout << ans <<endl;
  }
 
  return 0;
}
