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
  while( cin >>n){
    int odd =0, even =0;
    vi A(n); rep(i, 0, n) {
      cin >>A[i];
      if(A[i]%2) odd++;
      else even++;
    }
    if( odd  && even) sort(A.begin(),A.end());
    for( int x: A) cout << x << " "; cout <<endl;
  }
  return 0;
}
