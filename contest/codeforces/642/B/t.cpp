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
  cin >>t;
  while(t--){
    ll n,k;
    cin >> n >>k;
    vi A(n), B(n);
    rep(i, 0, n) cin >> A[i];
    rep(i, 0, n) cin >> B[i];
    sort(all(A));
    sort(all(B));

    ll sum = 0;
    int l = 0, r = n-1;
    while( k > 0 && l < n && r >= 0 ){
      if( B[r] > A[l]){
        swap( B[r--], A[l++]);
        k--;
      }else{
        r--;
      }
    }
    rep(i, 0, n) sum+=A[i];
    cout << sum <<endl;
  }


  return 0;
}
