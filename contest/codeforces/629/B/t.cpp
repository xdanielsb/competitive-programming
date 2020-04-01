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

ll gauss( ll n){
  return n*1ll*(n+1)/2;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin)) 
    cerr << "no file..."<<endl;
#endif

  int t; cin >> t;
  while( t--){
    ll n, k;
    cin >> n >> k;
    ll nk = (-1 + sqrt(1 + 8*k))/2 ;
    if( k == gauss(nk)){
      rep(i, 0, n-nk-1)cout<<'a';
      rep(i, 0, 2)cout<<'b';
      rep(i, 0, nk-2+1) cout <<'a';
      cout <<endl;
    }else{
      rep(i, 0, n-nk-2)cout<<'a';
      cout<<'b';
      ll aux = gauss(nk+1) - k;
      rep(i, 0, aux) cout << 'a';
      cout << 'b';
      rep(i, 0, nk-aux) cout <<'a';
      cout <<endl;

    }
  }
  return 0;
}
