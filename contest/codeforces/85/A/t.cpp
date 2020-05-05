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
    ll n;cin>>n;
    vector<ii> A(n); rep(i,0,n)cin >>A[i].F >> A[i].S;
    bool ok = A[0].F >= A[0].S;
    int losses = A[0].F - A[0].S;
    rep(i, 1, n){
      ok &= A[i].F >= A[i].S;
      ok &= (A[i].F -A[i].S >= losses);
      losses = max( losses, A[i].F - A[i].S);
      ok &= A[i].F >= A[i-1].F;
      ok &= A[i].S >= A[i-1].S;
    }
    printf(ok?"YES\n":"NO\n");
  }

  return 0;
}
