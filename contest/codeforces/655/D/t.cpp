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

  int n;
  while( cin >> n){
    vector< ll > A(n);
    for( int i = 0; i < n; i++){
      cin >> A[i];
    }
    // compute prefix
    vector< ll > prefix = A;
    for( int i = 0; i < n-2; i++){
      prefix[i+2] +=  prefix[i];
    }
    // compute suffix
    vector< ll > suffix = A;
    for( int i = n-3; i>=0; i--){
      suffix[i] += suffix[i+2];
    }

    ll ans = prefix[n-1];
    for( int i = 0; i < n-1; i++){
      ans = max(ans, (long long)prefix[i] + suffix[i+1]);
    }
    cout << ans <<endl;
  }
  return 0;
}
