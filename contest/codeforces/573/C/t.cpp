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
typedef pair<ll, ll> ii;
typedef vector<int> vi;


ll countDiv( ll num){
  ll ans = 0;
  for( ll i =1 ; i *1ll*i <= num; i++){
    if(num % i ) continue;
    ans+=2;
    if( i*1ll*i == num) ans--;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif


  int n;
  while( cin >> n ){
    ll x;
    cin >> x;
    ll gcd = x;
    rep(i, 1, n){
      cin >> x;
      gcd = __gcd( gcd, x);
    }
  //  debug1( gcd );
    ll ans = countDiv( gcd );
    cout << (ans) <<endl;
  }

  return 0;
}
