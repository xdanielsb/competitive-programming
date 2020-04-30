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
typedef unsigned long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAXN = 200+5;
ll Cnk[MAXN][MAXN];

void build(){
  rep(n, 0, MAXN) Cnk[n][0] = Cnk[n][n] = 1ll;
  rep(n, 1, MAXN){
    rep(k, 1, n){
      Cnk[n][k] = Cnk[n-1][k-1] + Cnk[n-1][k];
    }
  }
}
// this solution does not produce accurate results
// it is neccesary BigInteger or python
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int t; cin >>t;
  //build Cnk
  build();
  int n, k;
  while(t--){
    cin >> n >> k;
    if( k == 0){
      cout << 1 <<endl;
      continue;
    }
    vi p(k);
    int sum = 0;
    rep(i ,0 ,k ) {
      cin >> p[i]; sum+= p[i];
    }
    int b = n - sum; // number of blank squares
    if( b < k -1 ){
      // if the number of blanks squares is
      // less than the number of partitions
      cout << 0 <<endl;
      continue;
    }
    if( k > n-k) k = n-k;
    cout << Cnk[n-sum+1][k] <<endl;
  }
  return 0;
}
