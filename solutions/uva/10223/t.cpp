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

int dp[34];
map< ll, int > mp;

ll C( int n){
  if( ~dp[ n ] ) return dp[n];
  if( n <= 1) return dp[n] = 1;
  ll res = 0;
  rep(i,0 ,n) res += C(i) *1ll* C(n-i-1);
  mp[ res ] = n;
  /* debug2( n, res); */
  return dp[n] = res;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  
  ll n;
  mp[1] = 1;
  mp[0] = 1;
  memset( dp, -1, sizeof (dp));
  C(30);
  while( cin >> n){
    cout << mp[n] << endl;
  }
  return 0;
}
