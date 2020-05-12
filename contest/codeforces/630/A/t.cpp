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
  cin >> t;
  while(t--){
    ll a, b, c, d;
    cin >> a >> b >> c >>d;
    ll x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    ll dx = b-a, dy = d-c;
    bool ok = true;
    if( dx == 0 && x1 == x2 && (a || b)) ok =false;
    if( dy == 0 && y1 == y2 && (c || d)) ok =false;

    if(ok && x+dx <= x2 && x+dx >= x1 && y+dy <= y2 && y+dy >= y1){
      cout << "Yes\n";
    }else{
      cout << "No\n";
    }

  }
  return 0;
}
