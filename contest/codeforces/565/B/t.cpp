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

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  ll t; cin >>t;
  ll n;
  while( t--){
    cin >> n; vi A(n);
    ll ans = 0;
    vi cnt(3, 0);
    rep( i, 0, n){
      cin >>A[i];
      cnt[A[i]%3]++;
    }
    ll mn = min(cnt[1],cnt[2]);
    ans = cnt[0] + mn;

    cnt[1] -= mn;
    cnt[2] -= mn;

    ans += cnt[1]/3;
    ans += cnt[2]/3;
    cout << ans <<endl;
  }



  return 0;
}
