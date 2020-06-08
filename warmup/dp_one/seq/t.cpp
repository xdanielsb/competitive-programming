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

const int maxn = 3000 + 4;
int v[maxn];
int n;

int dp[maxn][maxn];
int cnt = 0;
// i pos
// la last element of a
int f( int i, int la, int lb){
  cnt++;
  int &ans = dp[la][lb];
  if( ~ans) return ans;
  if( i == n) return ans = (la>0 && lb >0)? 0: 1e6;
  //take i to the seq a
  ans = f(i+1, i, lb) + (v[i] - v[la]) * (v[i] - v[la]);
  //take i to the seq b
  ans = min( ans, f(i+1, la, i) + (v[i]- v[lb]) * (v[i] -v[lb]));
  return ans;
}
vi path;

void build( int i, int la, int lb){

  int &ans = dp[la][lb];
  if( i == n) return;
  //take i to the seq a
  if(ans == dp[i][ lb] + (v[i] - v[la]) * (v[i] - v[la])){
    build(i+1, i, lb);
  }
  else{
    path.PB(i);
    build(i+1, la, i);
  }
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif

  while( cin >>n ){
    memset(dp, -1, sizeof(dp));
    rep(i,0,n) cin >> v[i];
    int ans = f(0,0,0);

    rep(i, 0, n+1){
      rep(j,0,n+1)
        cout << dp[i][j] << " ";
      cout <<endl;
    }

    debug2( ans, cnt );
    build(0, 0,0);
    cout << "path" <<endl;
    for( int x: path) cout << v[x] << " "; cout <<endl;

  }


  return 0;
}
