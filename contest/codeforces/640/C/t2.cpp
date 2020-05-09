
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
    ll n, k;
    cin >> n >> k;
    if( k < n){
      cout << k << endl;
      continue;
    }
    ll l = 1, r = 2*k +1;
    /* debug2(n, k); */
    while( l <= r){
      ll mid  = ( l +r )>>1;
      ll aux = mid - mid/n ;
      if( aux >= k) {
        r = mid-1;
      }else{
        l = mid+1;
      }
    }
    cout << (r+1) <<endl;
  }

  return 0;
}
