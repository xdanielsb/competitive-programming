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
    int t; cin >>t ;
    int n, t1, t2;
    while( t--){
      cin >> n>>t1 >> t2;
      int mx1 = -1, mx2 =-1, aux;
      rep(i, 0, t1){
        cin >> aux;
        mx1 = max( aux, mx1);
      }
     rep(i, 0, t2){
        cin >> aux;
        mx2 = max( aux, mx2);
      }
      printf( mx1>mx2?"YES\n":"NO\n");
    }
  
  return 0;
}
