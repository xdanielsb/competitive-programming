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
  ll a ,b;
  while( cin >> a >> b){
    int aux = b-a;
    if( b == 1 && a == 9){
      cout << a << " " << 10 << endl;
      continue;
    }
    if( aux > 1 or aux <0 ){
      cout << -1 << endl;
    }else{
      aux = a - b;
      if( aux == 0){
        cout << a<< "0" << " " << b <<"1"<< endl;
      }else {
        cout << a << " " << b << endl;
      }
    }
  }
  
  
  return 0;
}
