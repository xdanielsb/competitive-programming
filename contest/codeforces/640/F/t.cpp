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
  int t ; cin >> t;
  while(t--){
    int a, b, c, lst=0;
    cin >> a >> b >>c;
    if( a) rep(i, 0, a+1) cout << '0';
    if( c) rep(i, 0, c+1) cout << '1';
    if( b){
      if( a > 0 && c > 0) b--;
      if( a== 0 && c ==0) b++;
      if( c > 0) lst = 1;
      while( b--){
        cout<< (lst?'0':'1'); lst^=1;
      }
    }
    cout<<endl;
  }

  return 0;
}
