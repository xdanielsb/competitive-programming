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
    ll n,m;

    cin >> n >> m;
    if( m > n){
      cout <<"NO" <<endl;
      continue;
    }
    if( (n-(m-1))%2 == 1){
      cout << "YES"<<endl;
      rep(i, 0, m-1) cout << 1 << " ";
      cout << (n-m+1) <<endl;
    }else if( 2*(m-1) < n && (n - 2*(m-1)) % 2 ==0 ){
      cout << "YES"<<endl;
      rep(i, 0, m-1) cout << 2 << " ";
      cout << (n -2*(m-1)) <<endl;
    }else{
      cout <<"NO" <<endl;
    }
  }


  return 0;
}
