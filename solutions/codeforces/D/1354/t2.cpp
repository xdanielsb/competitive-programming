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
typedef vector<int> vll;
struct fw {
  int n; vll data;
  fw(int _n) : n(_n), data(vll(_n)) { }
  void update(int at, ll by) {
    while(at < n) {
      data[at] += by;
      at |= at + 1;
    }
  }
  void update_range( int l, int r, ll by){
    update(l, by);
    update(r+1, -by);
  }
  int query(int at) {
    int res = 0;
    while(at >= 0) {
      res += data[at];
      at = (at & (at + 1)) - 1;
    }
    return res;
  }
};

int ni, qi;

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  while( cin >> ni >> qi){
    int n, q;
    int maxn = 1e6+10;
    fw fenwick(maxn);
    rep(i, 0, ni){
      cin >> n;
      fenwick.update(n, 1);
    }

    rep(i, 0, qi){
      cin >> q;
      if( q > 0){
        fenwick.update(q, 1);
      }else{
        int l=1, r = maxn-1;
        int mid = -1;
        while( l <= r){
          mid= (l+r)/2;
          if( fenwick.query(mid) >= abs(q)){
            r = mid-1;
          }
          else{
            l = mid+1;
          }
        }
        /* debug2(q, r+1); */
        fenwick.update(r+1, -1);
      }
    }

    int ans = 0;
    rep(i, 1, maxn){
      if( fenwick.query(i) > 0){
        ans = i;
        break;
      }
    }
    cout << ans <<endl;
  }


  return 0;
}
