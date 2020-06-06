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
const int maxn = 4e5 + 10;
ll arr[maxn];
ll pre[maxn]; // prefix days
ll sum[maxn]; // pref sum days
ll gauss( ll x ){
  return x * 1ll * (x+1) / 2;
}
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif

  ll n, x;
  while(cin >> n >> x){
    for( int i = 0; i < n; i++){
      cin >> arr[i];
      arr[i+n] = arr[i];
    }
    n = 2ll * n;
    sum[0] = pre[0] = 0;
    for( int i = 0;  i < n; i++){
      pre[i+1] = pre[i] + arr[i];
      sum[i+1] = sum[i] + gauss(arr[i]);
    }
    ll ans = 0;

    /* debug2(n, x); */
    for( int i = 0; i < n ; i++){
      /* debug1(pre[i+1]); */
      if( pre[i+1] >= x ){
        int ub = upper_bound(pre, pre+n, pre[i+1] - x ) - pre;
        ll cnt = sum[i+1] - sum[ub];
        // how many days left to be added
        int left = x - (pre[i+1] - pre[ub]);
        cnt += ( gauss(arr[ub-1]) - gauss(arr[ub-1]-left));
        ans = max(ans, cnt);
      }
    }
    cout << ans <<endl;

  }
  return 0;
}
