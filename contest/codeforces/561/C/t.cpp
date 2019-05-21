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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

int n;
while( cin >> n){
  vi A(n); rep( i, 0, n){
    cin >> A[i];
    if( A[i] <0) A[i] *= -1;
  }
  sort( A.begin(), A.end());
  ll ans = 0;
  rep( i, 0, n){
    int idx = upper_bound( A.begin(), A.end(), A[i]+A[i])- A.begin();
    ans += max(0, idx-i-1);
  }
  cout << ans <<endl;

}





  return 0;
}
