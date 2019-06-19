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

struct tri{
  int from, to, cost;
};
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  
  int n,m,k;
  while( cin >> n >>m >> k){
    vector< bool > sto(n+1, false);
    vector< tri > A(m);
    rep( i, 0, m) cin >> A[ i ].from >> A[i].to >> A[i] .cost;
    int aux =0;
    rep( i, 0, k){
      cin >> aux;
      sto[ aux ]  =true;
    }
    int ans = -1;
    rep( i, 0, m){
      if( (sto[ A[i].from ] + sto[ A[i].to]) == 1){
        if( ans == -1) ans = A[i].cost;
        else ans = min( ans, A[i].cost);
      }
    }
    cout << ans <<endl;
  }
  return 0;
}
