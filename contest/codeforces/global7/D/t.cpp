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


string solve(const string &a){
  string s = a;
  reverse( s.begin(), s.end());
  s = a + '#' + s;
  int c = 0;
  vi prefix(size(s));
  rep(i, 1, size( s)){
    while( c > 0 && s[i] != s[c])
      c = prefix[c-1];
    if( s[c] == s[i] )
      c++;
    prefix[i] = c;
  }
  return s.substr(0, c);
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int t;
  cin >> t;
  while( t--){
    string s;
    cin >> s;
    int l = 0, r = size(s) -1;
    while( l < r ){
      if( s[l] != s[r]) break;
      l++; r--;
    }
    if( l > 0){
      cout << s.substr(0, l);
    }
    if( size(s) > 2*l){
      string aux = s.substr(l, size(s)-2*l);
      string a = solve( aux );
      reverse(all(aux));
      string b = solve( aux );
      if( size(a) < size(b))
        swap(a, b);
      cout << a ;
    }
    if( l > 0){
      cout << s.substr( size(s)-l, l);
    }
    cout <<endl;
  }

  return 0;
}
