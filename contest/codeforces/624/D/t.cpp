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
  cin >>t;
  while(t--){
    vi A(3); rep(i, 0, 3) cin >> A[i];
    ll ans = 1e9;
    vi sol(3);
    rep(i, 1, 2*A[0]){
      for( int j = i;  j < 2 * A[1]; j +=i){
        rep(k, 0,2){
          ll aux = abs(A[0]-i) +  abs(A[1]-j);
          ll c =  j * (A[2]/j) +k*j;
          aux += abs(A[2] -c);
          if( ans > aux){
            sol[0] = i; sol[1] = j;  sol[2]= c;
            ans = aux;
          }
         }
        }
    }
    cout << ans <<endl;
    rep(i, 0, 3) cout << sol[i] << " "; cout <<endl; 
  }
  
  return 0;
}
