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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

string alph = "aeiou";

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  int n;
  while( cin >> n){
    bool ok = false;
    for( int i = 2; i *i <= n && !ok; i++){
      if( n % i == 0 ){
        if( i > 4 && (n/i) >4){
          ok = true;
          rep(j, 0, i){
            rep( k, 0, n/i){
              cout << alph[(j+k)%5];
            }
          }
          cout <<endl;
        }
      }
    }
    if(!ok){
      cout << -1 <<endl;
    }
  }





  return 0;
}
