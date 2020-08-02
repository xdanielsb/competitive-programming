#include <bits/stdc++.h>
#define endl '\n'
#define d(x) cout <<#x << " = " << x << ", ";
#define d1( x ) d(x); cout <<endl;
#define d2( x, y ) d(x); d(y); cout <<endl;
#define d3( x, y, z ) d(x); d(y); d(z); cout <<endl;
#define F first
#define S second
#define PB push_back
#define size( x )   int( ( x ).size( ) )
#define endl '\n'
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
  int t;
  cin >> t;
  while(t--){
    int n, k, l;
    cin >> n >> k >> l;
    vector< int > depth(n+1);
    vector< int > safe;
    safe.push_back(0);
    for( int i = 1; i <= n; i++){
      cin >> depth[i];
      if( depth[i] + k <= l) safe.push_back( i );
    }
    safe.push_back(n+1);
    bool ok = true;
    for( int i = 1; i < size(safe) && ok; i++){
      int tide = k; bool down = true;
      for( int j = safe[i-1] + 1; j < safe[i]; ++j){
        tide += down ? -1 :  1;
        if( down ) tide -= max(0, depth[j] + tide - l);
        if( tide < 0 || depth[j] + tide > l){
          ok = false;
          break;
        }
        if( tide == 0 ) down = false;
      }
    }
    printf(ok?"Yes\n":"No\n");
  }
  return 0;
}
