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
    char s[9][9];
    rep(i, 0, 9)
      rep(j, 0, 9)
      cin >>s[i][j];

    for( int i = 0; i< 3; i++){
      for (int j=0; j < 3; j++){
        char &x = s[j+3*i][ i+3*j];
        if( j+3*i < 7) x = s[j+3*i+1][i+3*j];
        else x = s[j+3*i-1][i+3*j];
      }
    }
    /* swap(s[8][0], s[8][1]); */
    rep(i,0,9){
      rep(j,0,9)
        cout << s[i][j];
      cout <<endl;
    }

  }
  return 0;
}
