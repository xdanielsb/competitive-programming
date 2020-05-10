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

  int t;
  cin >>t;
  while(t--){
    int n; cin >>n;
    vi A(n);
    rep(i,0 , n)cin >>A[i];

    // check front
    vi cnt(n+1, 0), cnt2(n+1, 0);
    int pos = 1;
    vector< bool > c1(n+1, false), c2(n+1, false);
    rep(i, 0, n){
      cnt[A[i]]++;
      while( cnt[pos]) pos++;
      if( pos-1 == i+1) c1[pos-1] = true;
    }
    pos = 1;
    for( int i= n-1, j=0; i>=0; i--, j++){
      cnt2[A[i]]++;
      while( cnt2[pos]) pos++;
      if( j+1 == pos-1) c2[i+1] = true;
    }
    vector< ii > ans;
    rep(i, 0, n+1){
      if( c1[i] && c2[i+1]){
        ans.PB({i, n-i});
      }
    }
    cout << size(ans)<<endl;
    rep(i, 0, size(ans)){
      cout << ans[i].F << " " << ans[i].S <<endl;
    }

  }
  return 0;
}
