/**
 *    author:  xdanielsb
 *    created: 2019-02-23  
**/
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
typedef long double ld;

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
 
  string s;
  int fact = 1;
  map< string , int > mp;
  for( int i= 1; i <= 10; i++){
    fact = fact * i;
    mp[ to_string( fact) ] = i;
  }

  while( cin >> s){
    int l  = size( s );
    if( l < 1 ){
      cout << s <<endl; 
      continue;
    }
    if( l < 8){
      cout << mp[ s ] <<endl;
      continue ;
    }

    ld aux = 0, i = 1;
    while( 1 ){
      aux += log10( i);
      if( aux >= l) break;
      i++;
    }
    cout << (i-1) <<endl;
  }
  
  
  
  return 0;
}
