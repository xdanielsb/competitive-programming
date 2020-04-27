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
const int maxn = 2e5 + 10;
int a[maxn], p[maxn],sim[maxn];

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int t; cin >>t;
  while( t--){
    int n;cin >>n;
    memset(sim, -1, sizeof(sim));
    rep(i, 0 , n) {
      cin >> a[i];
      p[a[i]] = i;
    }
    int l = n;
    bool ok = true;
    rep(i,1,n+1){
      if( sim[p[i]] == -1){
        sim[p[i]] = i;
        for( int j = p[i]+1; j < n && sim[j]==-1; j++){
          sim[j] = sim[j-1]+1;
        }
      }
      if( sim[p[i]] != a[p[i]]) ok = false;
    }
    /* rep(i, 0, n) cout << a[i] <<  " ";cout <<endl; */
    /* rep(i, 0, n) cout << sim[i] <<  " ";cout <<endl; */

    printf(ok?"Yes\n":"No\n");

  }


  return 0;
}
