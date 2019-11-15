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

int memo[105][105][105];

ll f( int a, int b, int c){
  ll ans1 =0, ans2 = 0;
  if(~memo[a][b][c]) return memo[a][b][c];
  if( a >= 1 && b >= 2) ans1 = 3 + f(a-1, b-2, c);
  if( b >= 1 && c >= 2) ans2 = 3 + f(a, b-1,c-2);
  return memo[a][b][c] = max( ans1, ans2);
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
 
  int q; cin >> q;
  int a , b, c;
  while( cin >> a >> b >> c){
    memset(memo, -1, sizeof( memo ));
    ll ans = f( a, b, c);
    cout << ans <<endl;
  }
  return 0;
}
