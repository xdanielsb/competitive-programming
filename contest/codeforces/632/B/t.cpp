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
  while( t--){
    int n;
    cin >> n;
    vi A(n), B(n);
    rep(i, 0, n)cin >> A[i];
    rep(i, 0, n) cin >> B[i];


    bool ok = true;
    int ni =0; //number of -1
    int yi =0; //number of +1
    rep(i, 0, n){
      if( A[i] < B[i] && yi == 0) ok = false;
      else if( A[i] > B[i] && ni == 0) ok = false;
      if(A[i] >0)yi++;
      if(A[i]<0)ni++;
    }
    printf(ok?"YES\n":"NO\n");

  }

  return 0;
}
