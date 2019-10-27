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
 
  int q, x,n;
  cin >> q;
  while( q--){
    cin >> n;
    priority_queue< int > p; int ans =0;
    rep(i, 0, n){
      cin >> x;
      if( p.empty() ){
        p.push(  x );
        continue;
      }
      while( !p.empty() && p.top()  > x ) {
        ans++;
        p.pop();
      }
      p.push(x );
    }
    cout << ans <<endl;
  }

  
  
  
  
  return 0;
}
