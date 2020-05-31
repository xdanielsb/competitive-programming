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
typedef vector<ll> vi;
map<ll, ll> pw;
ll n, k;
bool can( ll a){
  rep(i, 0, 63){
    ll r = a % k;
    a /= k;
    if( r > 1) return false;
    if( r == 1){
      if( pw.count(i)) return false;
      pw[i] = 1;
    }
  }
  return true;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif

  int t; cin >>t;
  while(t--){
    pw.clear();
    bool isPossible = true;
    cin >> n >> k;
    ll x;
    rep(i, 0, n) {
      cin >> x;
      if(x > 0 ){
        isPossible &= can(x);
      }
    }

    printf(isPossible?"Yes\n":"No\n");
  }
  return 0;
}
