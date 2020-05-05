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
typedef pair< pair<int, int>, int> iii;
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int t;cin >>t;
  while(t--){
    int n;cin >>n;
    vector< ii > h(n);
    for( ii &e: h) cin >> e.F >> e.S;
    ll ans = 0, mn = numeric_limits<ll>::max();
    rep(i, 0, n){
      int li = (i+n-1) % n;
      ans += h[i].F - min(h[i].F, h[li].S);
      mn = min(mn, min(h[i].F, h[li].S));
    }
    /* debug2(ans, mn); */
    cout << (ans+mn) << endl;


  }

  return 0;
}
