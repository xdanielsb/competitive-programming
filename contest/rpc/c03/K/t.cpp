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
const int mod = 26;

int toNum( char x){
  return x - 'a';
}
char toLet( int x){
  return x +'a';
}
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int n, m;
  while( cin >> n >> m){
    vector<char> text(n);
    vector<char> cipher(m);
    rep(i, 0, n) cin >> text[n-i-1];
    rep(i, 0, m) cin >> cipher[i];
    string ans = "";
    for( int i = m-1, j=0; i>=0; i--, j++){
      int diff = toNum(cipher[i])  - toNum(text[j]) ;
      diff %= mod;
      diff = (diff + mod) %mod;
      char let = toLet(diff);
      text.PB(let);
    }
    rep(i, 0, m) cout << text[m-i-1];
    cout <<endl;
  }

  return 0;
}
