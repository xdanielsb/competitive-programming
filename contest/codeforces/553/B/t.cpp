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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAXN = 500+15;
int arr[MAXN][MAXN];

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  int n,m;
  while( cin >> n >> m){
    rep( i, 0, n) rep( j, 0,m) cin >> arr[i][j];
    int aux = arr[0][0];
    rep( i, 1, n) aux ^= arr[i][0];
    vi ans(n, 0);
    bool in = false;
    if(aux == 0){
      rep(i, 0, n){
        rep( j, 0, m){
          if( aux ^ arr[i][0] ^arr[i][j]){
            in = true;
            ans[i] = j;
            break;
          }
        }
        if( in) break;
      }
    }
    if( aux || in){
      cout <<"TAK" <<endl;
      rep( i, 0, n) cout << ans[i]+1 <<" ";
      cout <<endl;
    }else{
      cout << "NIE"<<endl;
    }

  }

  return 0;
}
