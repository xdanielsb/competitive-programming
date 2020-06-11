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
const int maxn = 1000 + 10;
vector< int > G[maxn];
int deg[maxn];
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif

  int t;
  cin >> t;
  while(t--){
    memset(deg,0,sizeof(deg));
    int n, x;
    int from, to;
    int neigh = 0; //neighbors of x
    cin >> n >> x;
    /* debug2(n, x); */
    for( int i =0; i < n-1; i++){
      cin >> from >> to;
      deg[from]++;
      deg[to]++;
    }
    int winning = 0; // ayush = 0, ashish = 1
    if( deg[x] > 1){
      int others = n - deg[x] -1;
      /* debug1(others); */
      if( others % 2 == 1){
        winning = 1;
      }
      if( (deg[x]-1) &1 ) winning ^=1;
    }

    printf(winning==0?"Ayush\n":"Ashish\n");

  }
  return 0;
}
