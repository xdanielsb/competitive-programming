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
  cin >> t;
  while(t--){
    int n; cin >>n;
    vi A(n); rep(i, 0, n) cin >> A[i];
    sort(all(A));
    int ans = 0, i=0;
    while( i < n){
      int c = A[i], mx = A[i];
      while( i < n && c > 0 ){
        c--;
        if( A[i] > mx) {
          c += A[i] - mx;
          mx = A[i];
        }
        i++;
      }
      if( c <= 0 )
        ans++;
    }
    cout << ans <<endl;
  }
  return 0;
}
