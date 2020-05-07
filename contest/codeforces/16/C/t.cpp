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
  int t;cin >>t;
  while(t--){
    string s;
    cin >> s;
    set< pair<pair<int, int>, pair<int,int> >> vis;
    ll ans =0;
    int xi=0, yi=0, x=0, y=0;
    /* debug1(s); */
    for( int i= 0; i< size(s); i++){
      if( s[i] == 'N')y++;
      else if( s[i] == 'S')y--;
      else if( s[i] == 'W')x++;
      else if( s[i] == 'E')x--;

      if( vis.count(make_pair(make_pair(xi,yi),make_pair( x, y)))
          || vis.count(make_pair(make_pair(x,y  ),make_pair(xi,yi)))
        ){
        ans+=1;
      }
      else {
        ans+=5;
        vis.insert(make_pair(make_pair(xi,yi),make_pair( x, y)));
        vis.insert(make_pair(make_pair(x,y  ),make_pair(xi,yi)));
      }
      xi = x;
      yi = y;
    }
    cout << ans <<endl;

  }

  return 0;
}
