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
   int t; cin >> t;
   int n;
   while( t--){
    cin >>n;
    vi A(n );
    rep(i,0, n) cin >> A[i];
    bool ok = false;
    
    for( int j = 0; j < n-1 && !ok; j++){
      if(  max(A[j+1], A[j]) - min(A[j+1], A[j]) >= 2){
        ok = true;
        cout << "YES" <<endl;
        cout << j+1 <<  " " << j+2 << endl;
      }
    }
    if(!ok){
      cout << "NO" <<endl;
    }
   }
  return 0;
}
