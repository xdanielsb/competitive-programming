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


int dx[8] = {-2, -1, 1, 2, 0, 0, 0, 0};
int dy[8] = {0, 0,  0, 0, -2, -1, 1, 2};

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
    int n;
    cin >> n;
    vector< int > A(n);
    ll ans = 0;
    for( int i = 0; i < n; i++){
      cin >>A[i];
      if( i % 2 == 0) ans += A[i];
    }

    ll inc = 0; // max possible increment that we can generate
    ll aux = 0;
    for( int j = 0;  j < n-1; j+=2){
      aux += A[j+1] - A[j];
      if( aux  < 0 ) aux = 0;
      inc = max( aux, inc);
    }
    aux = 0;
    for( int j = 1; j < n-1; j+=2){
      aux += A[j] - A[j+1];
      if( aux < 0) aux = 0;
      inc = max( aux, inc);
    }
    cout << ans + inc <<endl;
  }
  
  return 0;
}
