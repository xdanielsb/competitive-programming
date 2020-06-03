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

  int t;cin >> t;
  while(t--){
    int n, x;
    cin >> n >> x;
    int aux;
    int odd=0,even= 0;
    rep(i, 0, n){
      cin >> aux;
      if( aux&1) odd++;
      else even++;
    }
    bool isOk = false;
    /* debug2(even, odd); */
    for( int i =1; i <= min(odd,x); i+=2){
      if( i + even >= x) isOk = true;
    }

    printf(isOk?"YES\n":"NO\n");
  }
  return 0;
}
