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
typedef unsigned long long ll;
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
    ll a, b;
    cin >> a >> b;
    if( a > b ) swap(a,b);
    int cnt = 0;
    int ndos = 0;
    while( a < b){
      a = a * 2ll;
      ndos++;
    }

    if( a != b){
      cout << -1 <<endl;
      continue;
    }
    int ans = 0;
    ans += ndos / 3;
    ndos %= 3;
    ans += ndos / 2;
    ndos %= 2;
    cout << (ans +ndos) <<endl;

  }
  
  return 0;
}
