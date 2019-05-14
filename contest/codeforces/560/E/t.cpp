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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

int mod =998244353 ;
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

 int n;
 while( cin >>n ){
   vector< ll >A(n), B(n);
   rep( i,0, n){
     cin >>A[i];
     A[i] = A[i]*(i+1)*(n-i);
   }
   rep( i,0, n){
     cin >> B[i];
   }
   ll ans =0;
   sort(A.begin(), A.end());
   sort(B.rbegin(), B.rend());

   rep( i,0 ,n){
     ans = (ans%mod + A[i]%mod *1ll* B[i]%mod);
     ans %= mod;
   }
   cout << ans <<endl;
 }




  return 0;
}
