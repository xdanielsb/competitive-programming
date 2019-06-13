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


int* compute(const string &t) {
  int m = size(t);
  int *p = new int[m];
  p[0]= 0;
  rep( i , 1 , m){
    p[i] = p[ i - 1 ]; 
    while( p[i] > 0 && t[i] != t[ p[i] ] ){
      p[i] = p[ p[i] -1 ];
    }
    if( t[i] == t[ p[i] ] ) p[i]++;
  }
 return p; 
}


int contains( const string &ne, const string &ha ){
  int m = size(ne),  n = size(ha);
  int *p = compute ( ne );
  int s = 0;
  rep( i, 0, n){
    while( s > 0 && ha[ i ] != ne[  s ] )
      s = p[ s - 1];
    if( ha[i] == ne[s] ) s++;
    if( s == m) return true;
  }
  return false;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
 
  int t;cin >>t;
  int x;
  string needle, haystack;
  while( t--){
    cin >> haystack;
    int *p = compute ( haystack);
    cin >>x;
    rep( i , 0 , x){
      cin >> needle;
      if( contains(needle, haystack)) cout << "y";
      else cout << "n";
      cout <<endl;
    }
  }
  return 0;
}
