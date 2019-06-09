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
//  ios::sync_with_stdio( false );
//  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  ll t,n; cin >> t;
  while( t--){
    int ans =0;
    cin >> n;
    bool ok=  true;
    while( n!=1){
      if( n%2 ==0){
        n = n/ 2;
      }else if ( n%3==0){
          n = 2*n/3;
      }
      else if ( n%5==0){
          n = 4*n/5;
      }else{
        ok = false;
        break;
      }
      ans++;
    }
    if(ok){
      cout  << ans <<endl;
    }else{
      cout << -1 <<endl;
    }
  }

  return 0;
}
