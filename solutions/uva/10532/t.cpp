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

const int maxn = 55;
ll B[maxn], k, n;
ll A[maxn];
ll dp[maxn][maxn];
ll Cnk( int i, int tot){
  if( tot == k ) return 1;
  if( i >= n) return 0;
  ll &ans = dp[i][tot];
  if(~ans ) return ans;
  ans = 0;
  for( int l= 0; l <= B[i]; l++){
    if( l + tot <= k)
      ans += Cnk(i+1, tot+l);
  }
  return ans;
}



int main(){
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  ll m;
  int c = 1;
  while( cin >> n >> m && n){
    printf("Case %d:\n", c++);
    memset(B,0, sizeof(B));
    memset(A,0, sizeof(A));
    map< int, int > cnt;
    rep(i, 0, n){
      cin >> A[i];
      cnt[A[i]]++;
    }

    int j= 0;
    for( ii x: cnt){
      B[j++]=x.S;
    }

    rep(i, 0, m){
      cin >> k;
      memset(dp, -1, sizeof(dp));
      ll ans = Cnk(0, 0);
      cout << ans <<endl;
    }
  }
  return 0;
}
