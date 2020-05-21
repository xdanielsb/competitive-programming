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
  while( t--){
    string s;
    cin >> s;
    int n = size(s);
    int ans = 2e5+10;
    set < char > diff;
    map< char, int > cnt;
    for( int l = 0, r = 0; r < n ; r++){
      cnt[s[r]]++;
      diff.insert(s[r]);
      while( l < r && cnt[s[l]] > 1){
        cnt[s[l]]--;
        l++;
      }
      if( size(diff) == 3){
        ans = min( ans, r - l +1);
      }
    }
    if( ans > 2e5) ans =0;
    cout << ans << endl;

  }

  return 0;
}
