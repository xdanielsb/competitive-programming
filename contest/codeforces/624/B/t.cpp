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
  int t; cin >> t;
  while( t--){
    int n, p, x;
    cin >> n >>p;
    vi A(n); rep(i, 0, n) cin >> A[i];
    set< int> P; rep(i, 0, p){ cin >> x; P.insert(x-1);};

    rep( i, 0, n){
      rep( j, 0, n-1){
        if( P.count(j) && A[j] > A[j+1]) swap(A[j], A[j+1]);
      }
    }
    bool ok = true;
    rep(i, 0, n-1) ok &=( A[i] <= A[i+1]);
    printf(ok?"YES\n":"NO\n");
  }
  return 0;
}
