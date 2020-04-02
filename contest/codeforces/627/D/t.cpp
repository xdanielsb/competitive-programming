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
   ll n; ll x, y;
   while( cin >> n){
     vi A(n), B(n),R;
     rep(i, 0, n) cin >>A[i];
     rep(i, 0, n) cin >>B[i];
     rep(i, 0,n ){
      R.PB(A[i]-B[i]);
     }
     sort(all(R));
     ll ans = 0;
     rep(i, 0, n){
       if(R[i] <= 0){
         x = (n- ll(lower_bound(all(R), -R[i] + 1)-R.begin()) );
        ans +=  x;
       }else{
        ans += (n-i-1);
       }
     }
     cout << ans <<endl;
   }
  
  return 0;
}
