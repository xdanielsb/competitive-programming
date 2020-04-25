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

  int t; cin >> t;
  while( t--){
    ll n; cin >>n;
    vi A(n); rep(i,0, n) cin >>A[i];

    ll ans = 0;
    for(int i= 0; i <n ;i++){
      int cur = A[i];
      /* debug1(cur); */
      if( cur > 0){
        int j=i, aux = cur;
        while( j <n  && A[j] > 0){
          aux = max( A[j], aux);
          j++;
        }
        i = j-1;
        /* debug1(aux); */
        ans += aux;
      }else{
        int j=i, aux = abs(cur);
        while( j <n  && A[j] < 0){
          aux = min( abs(A[j]), aux);
          j++;
        }
        i = j-1;
        /* debug1(aux); */
        ans -= aux;
      }
    }
    cout << ans <<endl;
  }


  return 0;
}
