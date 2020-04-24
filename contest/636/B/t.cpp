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
typedef vector<ll> vi;

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int t; cin >>t;
  while( t--){
    ll n; cin >>n;
    if( (n/2)%2 == 1){
      cout << "NO" <<endl; continue;
    }
    cout << "YES" <<endl;

    vi A(n);
    ll s1=0, s2=0;
    rep(i,0 ,n/2){
      A[i] = (i+1)*2;
      s1+= A[i];
      A[i + n/2] = A[i]-1;
      s2+= A[i+n/2];
    }
    s2+= n/2;
    A[n-1] += n/2;
    assert(s1 == s2);
    rep(i,0, n) cout <<A[i] << " "; cout <<endl;
  }

  return 0;
}
