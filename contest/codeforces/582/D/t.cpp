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

const int MAXN = 2e5 +18;
int ma[MAXN], cnt[MAXN];
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  int n, m;
  while( cin >> n >> m){
     vector< vi > A(n); vi B( n);
     rep(i, 0, n ) cin >> B[i], ma[ B[i] ]++;
     sort( all( B));
     memset( ma, sizeof( ma ), 0 );
     memset( cnt, sizeof( cnt ), 0);
     int ans = INT_MAX;
     rep( i, 0, n){
        int aux = B[i];
        int bb = 0;
        do{ 
          if( ma[aux] >= m) ans = min( ans, cnt[aux]); 
          aux /= 2;
          bb++;
          ma[ aux ]++;
          cnt[ aux ] += bb;
        }while( aux);
     }
     cout << ans <<endl;
  }
  return 0;
}
