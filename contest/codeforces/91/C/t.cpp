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
    ll n, x;
    cin >> n >> x;
    /* debug2(n,x); */
    vector< int > A(n);
    for( int i = 0; i < n; i++) cin >> A[i];
    sort(A.rbegin(), A.rend());
    int ans = 0;
    int cu = 0;// number of people in the current team
    int mi = 0;// minimun skill in the current team
    for( int i = 0; i < n; i++){
      if( cu == 0){
        mi = A[i];
        cu = 1;
      }else {
        mi = min(mi, A[i]);
        cu++;
      }
      /* debug2( cu, mi); */
      if( mi*cu*1ll >= x){
        ans++;
        cu = 0;
      }
    }
    cout << ans <<endl;
  }
  return 0;
}
