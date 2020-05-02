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
  int t; cin >>t;
  while(t--){
    int n;
    cin >>n;
    vi A(n);
    int mx=0;
    int diff = 0;
    map<int, int> cnt;
    rep(i, 0, n){
      cin >>A[i];
      cnt[A[i]]++;
      if( cnt[A[i]] == 1) diff++;
      mx = max(mx, cnt[A[i]]);
    }
    ll ans = min(diff-1, mx);
    if( diff-1 < mx && mx >diff) ans++;
    cout << ans <<endl;

  }

  return 0;
}
