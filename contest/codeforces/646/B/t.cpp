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


int find( string s, int on){
  int n = size(s);
  int ans = INT_MAX;
  int acum = 0;
  for( int i = 0; i < n; i++){
    acum += s[i] == '0';
    on -= s[i] == '1';
    ans = min(ans,acum+on);
  }
  return ans;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int t;
  string s;
  cin >> t;
  while(t--){
    cin >> s;
    int on = 0;
    for( int i = 0; i < size(s); i++) on +=s[i] == '1';
    int ans = min( on, size(s)-on);
    ans = min(ans,find( s, on));
    reverse(all(s));
    ans = min( ans, find(s, on));
    cout << ans <<endl;

  }

  return 0;
}
