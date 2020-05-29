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
const ll mod = 1000000009;
ll n,k;

typedef vector< vector <ll> > vvll;
/*
 * Learning; check the order of index to multiply the matrix
 * this is more efficient that do it in the traditional way.
 */
vvll mul( vector< vector<ll>> &A, vector< vector<ll>> &B){
  vvll ans(k, vector<ll>(k));
  rep(i,0, k){
    rep(ki, 0, k){
      if(A[i][ki] == 0)continue;
      rep(j, 0, k){
        ans[i][j] = ((ans[i][j])%mod + (A[i][ki] * 1ll * B[ki][j])%mod)%mod;
      }
    }
  }
  return ans;
}


ll expo( vvll &ma, ll e){
  vvll A(k, vector<ll>(k));
  rep(i, 0, k){
    rep(j, 0, k){
      A[i][j] = (i == j?1ll:0ll);
    }
  }
  while( e > 0){
    if(e&1){
      A = mul(A, ma);
    }
    e >>= 1ll;
    ma = mul(ma, ma);
  }

  return A[0][0];
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  while( cin >> k >> n){
    if( n == 0 && k == 0) break;
    if( k== 0){
      cout << 1 << endl;
      continue;
    }
    vvll ma(k, vector<ll>(k));
    rep(i,0,k) ma[0][i] = 1;
    rep(i,1,k) ma[i][i-1] = 1;
    ll ans = expo( ma, n);
    cout << ans <<endl;
  }
  return 0;
}
