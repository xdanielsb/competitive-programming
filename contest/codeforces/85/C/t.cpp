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
typedef pair< pair<int, int>, int> iii;
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int t;cin >>t;
  while(t--){
    int n; ll ans =0;
    cin >>n ; vector<ii > A(n);
    rep(i, 0, n) cin >>A[i].F >> A[i].S;
    int pos=0, best = INT_MAX;
    rep(i,0, n){
      ll points = A[i].F - max(0,(A[i].F-A[(i-1+n)%n].S));
      /* debug2(A[i].F, points); */
      if( best > points){
        pos = i;
        best = points;
      }
    }
    rep(i, 0, n){
      int p = (i+pos)%n;
      int np = (i+pos+1)%n;
      A[np].F = max(0,A[np].F - A[p].S);
      ans += A[p].F;
    }
    cout << ans <<endl;
  }

  return 0;
}
