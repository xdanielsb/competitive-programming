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

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif

  int t;cin >>t;
  while(t--){
    int n, k;
    cin >> n>>k;
    /* debug2(n,k); */
    vi cnt(2*k+1, 0), pre(2*k+2, 0);
    vi A(n); rep(i, 0, n) cin >>A[i];

    bool ok = false;
    rep(i,0 , n/2){
      int sum = A[i] +A[n-i-1];
      pre[min(A[i], A[n-i-1])+1]++;
      pre[max(A[i], A[n-i-1])+k+1]--;

      cnt[sum ]++;
      if( cnt[sum] == n/2){
        ok = true;
      }
    }
    rep(i, 1, 2*k+2){
      pre[i] = pre[i]+pre[i-1];
    }

    if( ok ){
      cout << 0 << endl;
      continue;
    }
    int ans = 1e9;
    for( int i= 2; i <= 2 *k ; i++){
      //             the ones who can // the ones who need complete change
      ans = min( ans, pre[i]-cnt[i] + (n/2 - pre[i])*2);
    }
    cout << ans <<endl;
  }
  return 0;

}
