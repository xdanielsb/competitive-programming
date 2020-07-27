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
    int who = 0;
    int change = false; // check if there was an x greater than 1
    int x, n; cin >> n;

    for( int i = 0; i < n; i++){
      cin >> x;
      if( change ) continue;
      if( x == 1){
        who ^= 1;
      }else{
        // the first one that has a number greater than 1
        // is the winner
        who ^= 1;
        change = true;
      }
    }
    printf(who?"First\n":"Second\n");
  }
  
  return 0;
}
