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


ll gcd (ll a, ll b){
  if( b == 0) return a;
  return gcd(b, a%b);
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int n;
  while(cin >> n){
    vector< ll > A(n); rep(i, 0, n) cin >> A[i];
    vector< ll > suf(n);
    suf[n-1] = A[n-1];
    for( int i = n-2; i >=0 ; i--)
      suf[i] = gcd( suf[i+1], A[i]);
    ll ans;
    rep(i ,0, n-1){
      ll aux = A[i]*1ll*suf[i+1]/gcd(A[i], suf[i+1]);
      ans = i == 0? aux: gcd( ans, aux);
    }
    cout << ans <<endl;


  }
  return 0;
}
