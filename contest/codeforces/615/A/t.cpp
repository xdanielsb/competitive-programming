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
   while( t--){
      vector<ll> A(3); int n;
      rep(i, 0, 3) cin >> A[i]; cin >> n;
      sort(all(A));
      rep(i, 0, 3){
        n-= (A[2] - A[i]);
      }
      if( n < 0 || n%3 != 0){
        cout << "NO" <<endl;
      }else{
        cout << "YES" <<endl;
      }
   }  

  
  return 0;
}
