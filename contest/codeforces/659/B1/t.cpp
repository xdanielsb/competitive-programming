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

const int maxn = 1e5;
int depth[maxn];
int inc[maxn];
int n, k, l;

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int t;
  cin >> t;
  while(t--){
    cin >> n >> k >> l;
    vector< int > depth(n);
    d3(n, k, l);
    for( int i = 0; i < n ; ++i){
      cin >> depth[i];
      inc[i] = l - depth[i];
      cout << inc[i] << " ";
    }
    cout <<endl;
    bool ok = true;
    int lst = 0;
    printf(ok?"Yes\n":"No\n");
  }
  return 0;
}
