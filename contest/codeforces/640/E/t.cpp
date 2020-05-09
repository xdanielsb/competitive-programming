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
int dp[2][8000];
int arr[8000];
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int t; cin >>t;
  while(t--){
    int n, mx=-1; cin >>n;
    set< int> can;
    rep(i,0 , n) cin >> arr[i], mx = max(mx, arr[i]);
    rep(i, 1, n) {
      dp[0][i] = arr[i] +arr[i-1];
      if( dp[0][i] <= mx)
        can.insert(dp[0][i]);
    }
    rep(i, 1, n){
      rep(j, i+1, n){
        dp[i%2][j] = arr[j] + dp[(i-1)%2][j-1];
        if( dp[i%2][j] <= mx)
          can.insert(dp[i%2][j]);
      }
    }
    int ans =0;
    rep(i,0,n) if( can.count(arr[i])) ans++;
    cout << ans <<endl;
  }

  return 0;
}
