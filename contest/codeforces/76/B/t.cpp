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

  int q; cin >> q;
  ll a , b;
  while( q--){
    cin >> a >> b;
    set< int > ss;
    bool ok=  false;
    do{
      ss.insert( a );
      if(a >= b){
        ok = true;
        break;
      }
      if( a&1) a--;
      else a = a*3ll/2ll;
    }while( ss.count(a ) ==0);
    if( ok ){
      cout <<"yes";
    }else{
      cout << "no";
    }
    cout <<endl;
  }
  
  
  return 0;
}
