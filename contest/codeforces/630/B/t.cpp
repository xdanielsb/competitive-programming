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
    int n; cin >> n;
    vi A(n); rep(i, 0, n) cin >> A[i];
    int cnt =1;
    vi ans(n);
    vector<bool> vis(n, false);
    for( int  j = 2; j < 1000; j++ ){
      bool in = false;
      rep(i, 0, n){
        if( vis[i] ) continue;
        if(A[i] % j == 0){
          vis[i] = true;
          ans[i] = cnt;
          in = true;
        }
      }
      if( in)cnt++;
    }
    cout << (cnt-1) << endl;
    for( int i: ans) cout << i << " ";cout <<endl;
  }

  return 0;
}
