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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  ll n,m, ta, tb,k;
  while( cin >> n >> m >> ta >> tb >> k){
    vi A(n); rep( i, 0, n) cin >> A[i], A[i]+=ta;
    vi B(m); rep( i, 0, m) cin >> B[i];
    if( k >= n){
      cout << -1 <<endl;
      continue;
    }
    ll idx =0, lo=0, ans=-1;
    rep( i, 0, k+1){
      lo = lower_bound( B.begin(), B.end(), A[i]) - B.begin();
      lo += k-i;
      if( lo >= m){
        ans = -1;
        break;
      }
      ans = max(ans, B[lo]+tb);
    }
    cout << ans <<endl;

  }

  return 0;
}
