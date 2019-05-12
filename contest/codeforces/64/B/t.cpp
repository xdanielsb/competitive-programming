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



int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int t; cin >>t;
  string s;
  while(t--){
    cin >> s;
    sort( s.begin(), s.end());
    string a, b;
    for( char &c: s){
      if( c %2 ) a.PB( c);
      else b.PB( c);
    }
    /* debug2( a, b); */
    if( abs(a.back()-*b.begin()) != 1){
      cout << a << b <<endl;
    }else if( abs(b.back()-*a.begin()) != 1){
      cout << b << a << endl;
    }else{
      cout << "No answer" <<endl;
    }
  }
  return 0;
}
