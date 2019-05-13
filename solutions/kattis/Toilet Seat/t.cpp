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
  string s;
  while( cin >> s){
    int si = size( s );
    int a =0, b=0, c=0;
    char lsta=s[0], lstb=s[0];
    rep( i , 1, si){
      if( s[ i ] != s[ i-1 ]) c++;
      if( lsta != s[i] ) a++;
      if( s[i] != 'U') a++;
      lsta = 'U';

      if( lstb != s[i]) b++;
      if( s[i] != 'D') b++;
      lstb = 'D';
    }
    cout << a <<endl;
    cout << b<< endl;
    cout <<c <<endl;
  }
  return 0;
}
