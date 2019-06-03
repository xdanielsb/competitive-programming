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
typedef vector<int> vi;

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

 int n;
 while( cin >>n ){
   vi A(n+1); int cnt = 1;
   vector< bool > check(n+1, false);
   for( int i =2; i<=n; i++){
     if( check[i]) continue;
     for( int j = i; j<=n;j+=i){
       check[j] = true;
       A[j] = cnt;
     }
     cnt++;
   }
   rep(i, 2, n+1) cout <<A[i] << " ";
   cout <<endl;
 }




  return 0;
}
