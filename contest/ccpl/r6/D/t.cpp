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
    int x,y, n;
    cin >> x >> y >> n;
    for (int i = 1; i<=n; i++){
      if( i % x == 0 && i % y == 0){
        cout << "FizzBuzz" <<endl;
      }else if( i%x ==0){
        cout << "Fizz"<<endl;
      }else if( i%y == 0){
        cout << "Buzz"<<endl;
      }else{
        cout << i<< endl;
      }
    }
  }
  
  return 0;
}
