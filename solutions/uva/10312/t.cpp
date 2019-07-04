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
ll dpC[30], dpS[30];
/*
  also 2n!/((n+1)! n!)
  Catalan
*/
ll C( int n){
  if( ~dpC[n] ) return dpC[n];

  if ( n <= 1 ) return dpC[n]= 1;
  ll res = 0;
  for( int i= 0; i < n; i++)
    res += C(i) * C( n -i -1);
  return dpC[n] =res;
}

/*
  Super Catalan
*/
ll S( int n ){
  if( ~dpS[n] ) return dpS[n];
  if( n <=2 ) return dpS[n]=1;
  ll res =((6*n-9)*S(n-1)-(n-3)*S(n-2))/n;
  return dpS[n] = res;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
 
  int n;
  memset( dpC, -1, sizeof( dpC)); 
  memset( dpS, -1, sizeof( dpS)); 
  C(27); S(27);
  while( cin >> n ){
    ll ans = dpS[n] - dpC[n-1];
    cout << ans << endl;
  }
  
  return 0;
}
