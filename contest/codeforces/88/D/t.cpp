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

  int n;
  while (cin >> n){
    vi A(n);
    for( int &a: A) cin >> a;
    ll ans = 0;
    for( int i = 0 ; i <= 31; i++){
      ll mn = 0, cur = 0;
      for( int j = 0; j < n; j++){
        cur += (A[j] > i) ? -1e9: A[j];
        mn  = min(mn, cur);
        ans = max(ans, (cur-mn)-i);
      }
    }
    cout << ans <<endl;
  }
  return 0;
}
