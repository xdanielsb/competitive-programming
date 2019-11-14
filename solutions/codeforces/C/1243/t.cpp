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

ll solve( ll n ){
  vi divs;
  ll r = n;
  ll i = 2;
  for( ; i*1ll*i <= n ; i++){
    if( n % i == 0){
      divs.PB( i );
      while( n % i == 0) n/=i;
    }
  }
  if( r == n) return n; // prime
  if( n > 1) divs.PB( n);
  if( size( divs ) > 1) return 1;
  return divs[0];
}


int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
 
  ll n;
  while( cin >> n ){
     ll res =  solve( n );
     cout << res << endl;
  }
  return 0;
}
