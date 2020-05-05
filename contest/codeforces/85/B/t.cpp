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
  int t; cin >>t;
  while(t--){
    ll n, x; cin >>n >> x;

    vi A(n);
    ll sum = 0;
    rep(i,0, n){
      cin>>A[i];
      if( A[i] > x){
        sum +=A[i]-x;
        A[i]= x;
      }
    }
    sort(A.rbegin(), A.rend());
    int ans = 0;
    rep(i, 0, n){
      if( A[i] >= x) ans++;
      else if( x - A[i] <= sum){
        ans++;
        sum -= (x-A[i]);
      }
    }

    cout << ans <<endl;




  }
  return 0;
}
