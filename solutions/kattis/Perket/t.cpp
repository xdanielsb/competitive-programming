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
  int t;
  while( cin >> t){
    vector< ii >A(t);
    rep( i, 0, t) cin >>A[i].F >>A[i].S;
    ll best = LONG_LONG_MAX;
    rep(i, 0, 1<<10){
      ll sour=1, bit=0;bool in =0;
      rep(j, 0, t){
        if( i &(1<<j)){
            sour = sour * 1ll * A[j].F;
            bit += A[j].S;
            in = true;
        }
      }
      if( in )
        best = min( best, abs( sour -bit));
    }
    cout << best <<endl;
  }
  return 0;
}
