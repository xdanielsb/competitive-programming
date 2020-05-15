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

const int maxn = 1e5 + 10;
int A[maxn];
int n;
int find( int p){
  int ans = 1;
  for( int i = p+p; i <= n; i+= p){
    if( A[i] > A[p]){
      ans = max( ans, 1+ find( i ));
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
  int t; cin >>t;
  while( t--){
    cin >> n;
    rep(i, 1, n+1) cin >> A[i];
    int ans = 1;
    for( int i = 1; i <= n;  i++)
      ans = max(ans, find(i));

    cout << ans << endl;

  }

  return 0;
}
