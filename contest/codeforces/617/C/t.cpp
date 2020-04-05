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

  int t; cin >>t;
  while( t--){
    ll n; char s;
    cin >> n;
    int l, r, mn= 3e5 +1;;
    int x= 0, y = 0;
    map< ii, int > vis; 
    vis[{0,0}] = 1;
    bool enter = false;
    rep(i, 2, n+2){
      cin >>s ;
      if( s == 'L'){
        x--;
      }else if( s == 'R'){
        x++;
      }else if( s == 'U'){
        y++;
      }else if( s == 'D'){
        y--;
      }
      if( vis.find({x,y}) != vis.end()){
        if( (i - vis[{x,y}]) < mn){
          enter = true;
          l = vis[{x,y}] ; 
          r = i -1;
          mn = r - l;
        }
      }
      vis[{x,y}] = i;
    }
    if (enter)
    cout << l << " " << r <<endl;
    else cout << -1 <<endl;
  }
  return 0;
}
