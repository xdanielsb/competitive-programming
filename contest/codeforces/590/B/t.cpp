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
  freopen("in", "r" , stdin);
#endif
  int n,k;
  while( cin >> n >>k  ){
    queue < int > q; set < int > vis;
    int key;
    rep(i, 0, n){
      cin >>key;
      if( !vis.count( key)){
        q.push( key); vis.insert(key);
      }
      if( size(vis) > k){
        int top  = q.front(); q.pop();
        vis.erase( top);
      }
    }
    n = size(q);
    cout << size(q) <<endl;
    vector< int > ans;
    while( !q.empty()){
      ans.PB( q.front());
      q.pop();
    }
    rep(i, 0, n){
      cout << ans[n-i-1] << " ";
    }
    cout <<endl;
  }
  return 0;
}
