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
  int n, m;
  while(t--){
    cin >> n >> m;
    vector< char > c(n); rep(i, 0, n) cin >> c[i];
    sort(all(c));
    vector< string > ans(m);
    rep(i, 0, m) ans[i].PB(c[i]);
    /* debug1(ans[0]); */
    if( ans[0] != ans[m-1]){
      cout << ans[m-1] <<endl;
      continue;
    }

    if( c[m] == c.back()){
      cout << ans[0];
      rep(i, 0, (n-1)/m) cout << c[m]; cout <<endl;

    }else{
      cout << ans[0];
      rep(i, m, n) cout << c[i]; cout <<endl;
    }
  }
  return 0;
}
