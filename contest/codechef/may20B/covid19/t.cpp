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

  int n;
  int t; cin >> t;
  while( t--){
    cin >>n;
    vector< int >A(n);
    rep(i, 0, n)  cin >> A[i];
    sort(all(A));
    int best=1; // the more infected possible number
    int worst=n;// the less infected possible number
    int aux = 1;
    rep(i, 1, n){
      /* debug2(A[i], A[i-1]); */
      if( A[i]-A[i-1] <= 2){
        aux++;
      }
      else {
        best = max( best, aux);
        worst = min(worst, aux);
        aux = 1;
      }
    }

    best = max( best, aux);
    worst = min(worst, aux);
    cout <<worst<< " " << best <<endl;
  }


  return 0;
}
