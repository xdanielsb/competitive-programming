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

ll n, a, b, k;
vector< ll > A;

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin)) 
    cerr << "no file..."<<endl;
#endif
  ll x, aux;
  while( cin >> n >> a >> b >> k){
    A.clear();
    rep(i, 0, n){
      cin >> aux;
      A.PB( aux );
      A[i] %= (a+b);
      if(A[i] == 0) A[i] = a+b;
      A[i] = ( (A[i] + a -1) / a) -1;
    }
    sort(all(A));
    ll ans =0;
    rep(i, 0, n){
      if(k - A[i] <0 ) break;
       ans++;
       k-= A[i];
    }
    cout << ans <<endl;
  }
  
  return 0;
}
