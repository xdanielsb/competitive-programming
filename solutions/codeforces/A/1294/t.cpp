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
  freopen("in", "r" , stdin);
#endif


  int t;
  cin >> t;
  while( t-- ){
    ll a[3], n;
    rep( i, 0, 3) cin >> a[i];
    cin >> n;
    sort( a, a+3);
    int ans = a[2]-a[0]  + a[2]-a[1];
    n -= ans;
    if( n < 0 || n % 3 != 0){
      cout << "NO" <<endl;
    }else{
      cout << "YES" << endl;
    }
  }




  return 0;
}
