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
  freopen("in", "r" , stdin);
#endif

  vector< int> A;
  rep(i, 0, 32){
    rep(j, 0, 32){
      int aux = pow(2, i) * pow(3,j);

      if( aux > 0) {
        A.PB(aux);
        //cout << aux << " ";
      }
    }
  }
  sort( all(A));
  ll l, r;
  while( cin >> l >>r){
    auto a = lower_bound( all(A), l)-A.begin();
    auto b = lower_bound( all(A), r+1)-A.begin();
    int res = b - a ;
    //debug2( A[a],A[b] );
    cout <<res << endl;
  }


  return 0;
}
