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

  string x;
  while( cin >> x ){
    int cnt = (x.find("FBI") != string::npos);
    if( cnt){
      cout << 1;
    }
    for( int i = 2; i <= 5; i++){
      cin >>x;
      bool is = x.find("FBI") != string::npos;
      if( is){
        if( cnt) cout << " ";
        cout << i;
        cnt++;
      }
    }
    if( cnt == 0) cout <<"HE GOT AWAY!";
    cout <<endl;

  }
  
  
  
  
  return 0;
}
