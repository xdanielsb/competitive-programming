#include <bits/stdc++.h>
#define endl '\n'
#define debug1( x ) cout << #x << " = " <<  x << endl;
#define debug2( x, y) cout <<#x << " = " << x << " , " <<#y << " = " << y <<endl;
#define F real()
#define S imag()
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
typedef long double ld;

ld area( vector < complex<int> > &A, int n){ 
  ld ans = 0;
  rep(i, 1, n){
    complex< int> X = A[i]-A[0], Y = A[(i+1)%n]-A[0];
    ans += (X.F*1ll*Y.S)-(X.S*1ll*Y.F);
  }
  return fabs(ans/2.0);
}
// get Boundary points 
ll getP( vector< complex< int > > &A, int n){
  ll ans = 0;
  rep(i, 0, n){
    complex< int> X = A[i]-A[(i+1)%n];
    ans += abs(__gcd(X.F, X.S));
  }
  return ans;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  int n;int x, y;
  while( cin >> n && n){
    vector< complex<int> > A(n);
    rep( i, 0, n){
      cin >> x >> y;
      A[i] ={ x,y};
    }

    ld a = area( A, n);
    ll b = getP(A, n);
    ll ans = a - b/2 +1;
    cout << ans <<endl;

  }
  
  return 0;
}
