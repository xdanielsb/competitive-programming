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


ll f( ll n){
  for( ll i = 2; i * 1ll * i <= n; i++){
    if( n % i == 0 ) return i;
  }
  return n;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif

  int t;cin  >>t;
  while(t--){
    ll n, k;
    cin >> n >> k;
    ll ans = n + f(n);
    if( ans % 2){
      cout << (ans + f(ans) + max(0ll, 2*(k-2)));
    }else{
      cout << (ans + 2*(k-1)) <<endl;
    }

  }


  return 0;
}
