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

ll compute(ll a, ll b, ll c){
  return (a-b)*(a-b) + (a-c)*(a-c) +(b-c)*(b-c);
}

ll solve(vi &A, vi &B, vi &C ){
  ll ans = numeric_limits<ll>::max();
  for( ll x: A){
    auto lb1 = lower_bound(all(B), x) - B.begin();
    auto lb2 = lower_bound(all(C), x) - C.begin();
    /* cout << x << " " << B[lb1] << " " << C[lb2] << endl; */
    rep(i, -1, 2){
      rep(j, -1, 2){
        if( lb1 +i < 0 || lb2+j < 0) continue;
        if( lb1 +i >= size(B) || lb2+j >= size(C)) continue;
        ans = min(ans, compute(x, B[lb1+i], C[lb2+j]));
      }
    }
  }
  return ans;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int t;
  int na, nb, nc;
  cin >>t ;
  while(t--){
    cin >> na >>nb >> nc;
    vi A(na), B(nb), C(nc);
    rep(i, 0, na) cin >>A[i];
    rep(i, 0, nb) cin >>B[i];
    rep(i, 0, nc) cin >> C[i];
    sort(all(A));
    sort(all(B));
    sort(all(C));
    ll ans = min(solve(A,B,C), solve(A,C,B));
    ans = min(ans, min(solve(B, A, C), solve(B, C, A)));
    ans = min(ans, min(solve(C, A, B), solve(C, B, A)));
    cout << ans <<endl;

  }
  return 0;
}
