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

  int t, n;
  cin >> t;
  while( t-- ){
    cin >> n;
    vector< int > A(n);
    int mx = -1;
    for( int i = 0; i < n; i++) cin >> A[i];
    mx = *max_element(all(A));
    string ans(mx+1, 'a');
    cout << ans << endl;
    for( int i = 0; i < n; i++){
      ans[A[i]] = ans[A[i]] == 'z' ? 'a' : ++ans[A[i]];
      cout << ans <<endl;
    }
  }
 
  return 0;
}
