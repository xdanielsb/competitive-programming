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

  int n, m;
  while( cin >> n>>m){
    vector<int>  A(105, 0);
    int l, r;
    rep(i,0 ,m ){
      cin >> l >>r;
      rep(j, l,r+1) A[j]++;
    }
    bool ok = true;
    rep(i, 1, n+1){
    //  debug1(A[i]);
      if( A[i] > 1  || A[i] ==0){
        ok = false;
        cout << (i) << " " <<A[i] <<endl;
        break;
      }
    }
    if( ok ){
      cout << "OK" <<endl;
    }

  }




  return 0;
}
