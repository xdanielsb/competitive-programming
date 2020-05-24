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

const int maxn = 1e6+10;
int a[maxn], q[maxn];

int ni, qi;
bool find( int x){
  int leq = 0; //less or equal to x
  rep(i, 0, ni) leq += (a[i] <= x);
  rep(i, 0, qi){
    if( q[i] > 0){
      leq += (q[i] <= x);
    }else{
      leq -= (abs(q[i]) <= leq);
    }
  }
  return leq;
}
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  while( cin >> ni >> qi){
    rep(i, 0, ni) cin >> a[i];
    rep(i, 0, qi) cin >> q[i];
    int l = 1, r = maxn;
    int ans = 0;
    while( l <= r){
      int mid = (l+r)/2;
      /* debug2(mid, find(mid)); */
      if( find( mid ) > 0){
        ans = mid;
        r = mid-1;
      }else{
        l = mid+1;
      }
    }
    cout << ans <<endl;
  }





  return 0;
}
