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
typedef pair< ii, int> iii;
typedef vector<int> vi;

const int maxn = 2e5 +10;
int cnt[maxn];

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif

  int n;
  while( cin >> n ){
    vi G(n), ids(n);
    int from, to;
    memset(cnt, 0, sizeof(cnt));
    int best=-1, bestPos = -1;
    vector< ii > pi;
    rep(i, 0, n-1){
      cin >> from >> to;
      from--; to--;
      pi.PB({from, to});
      cnt[from]++;
      cnt[to]++;
      if( cnt[from] > best){
        best = cnt[from];
        bestPos = from;
      }
      if( cnt[to] > best){
        best= cnt[to];
        bestPos = to;
      }
    }

    vi ans(n-1);
    int count = 1;
    rep(i, 0, n-1){
      if( pi[i].F == bestPos || pi[i].S == bestPos){
        ans[i] = count++;
      }
    }
    /* rep(i, 0, n-1){ */
    /* debug2( i, ans[i]); */
    /* } */
    rep(i, 0, n-1){
      if( ans[i] == 0) ans[i] = count++;
    }
    rep(i, 0, n-1)
      cout << ans[i]-1 <<endl;



  }
  return 0;
}
