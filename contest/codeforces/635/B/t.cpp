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
  while(t--){
    ll l, a, b;
    cin >> l >> a >> b;

    bool ok = false;
    for( int i= 0; i < a; i++){
      if( b && l <= 10) ok = true;
      l = l/2 + 10;
    }
    l-= b*10;
    if( ok || l<= 0){
      cout <<"YES\n";
      continue;
    }
    cout << "NO\n";


  }

  return 0;
}
