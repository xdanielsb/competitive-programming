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

 int n, x, y;
 while( cin >> n >>x >>y){
   vector<char> A(n); rep(i, 0, n) cin >>A[i];
   int ans = 0;
   for( int i= 0; i <y; i++){
     if( A[n-1-i] == '1') ans++;
   }
   if(A[n-1-y]=='0')ans++;
   for(int i= y+1; i <x ; i++){
     if( A[n-1-i] == '1') ans++;
   }
   cout << ans <<endl;
 }




  return 0;
}
