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
  int q; cin >> q;
  int n;
  while( q--){
    cin >> n; vi A(n);
    rep(i, 0, n) cin >> A[i];
    map<int, int >  cnt;
    int l =0, r=1;
    int ans = -1;
    cnt[A[0]]++;
    while( r <n && l <= r){
      cnt[A[r]]++;
      bool enter = false;
      while( cnt[A[r]] > 1){
        enter = true;
        cnt[A[l++]]--;
      }
      if( enter ){
        /* debug2( l, r); */
        if( ans == -1) ans = r-l+2;
        else ans = min( ans, r-l+2);
      }
      r++;
    }
    cout << ans <<endl;
  }
  
  return 0;
}
