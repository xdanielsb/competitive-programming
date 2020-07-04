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
   int n, k;
   cin >> t;
   while(t--){
      cin >> n >> k;
      /* debug2(n,k ); */
      if(k%n==0)cout<< 0 <<endl;
      else cout << 2 <<endl;
      vector< vector< char > > m( n, vector<char>(n));
      for( int i = 0; i < n; i++){
        for( int j = 0; j < n; j++){
          m[i][j] = '0';
        }
      }
      int r =0, c = 0;
      while(k){
        k--;  
        m[r++][c++] = '1';
        c%=n;
        if( r == n){
          r = 0; c++; c%=n;
        }
      }
      for( int i = 0; i < n; i++){
        for( int j = 0; j < n; j++){
          cout <<m[i][j];
        }
        cout <<endl;
      }
   }
  return 0;
}
