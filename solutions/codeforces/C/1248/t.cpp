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
const int MAXN =(int)1e5+100;
const int mod = (int) (1e9+7);
ll fibo[MAXN];

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
    
  int n, m;
  fibo[0] = fibo[1] = 1;
  rep(i, 2, MAXN)
    fibo[ i ] = (fibo[ i-1] + fibo[i-2])%mod;

  while( cin >> n >> m){
    ll ans = 2*( fibo[n] + fibo[m] -1);
    cout << ans%mod <<endl;
  }
  return 0;
}
