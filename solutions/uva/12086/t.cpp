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
typedef vector<ll> vi;

struct fw {
  int n; vi data;
  fw(int _n) : n(_n), data(vi(_n)) { }
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
  ll query(int at) {
   ll res = 0LL;
   while(at >= 0) {
     res += data[at];
     at = (at & (at + 1)) - 1;
   }
   return res;
  }
};
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  int n;
  string op; int x,y;
  int cas = 1;
  while( cin >> n && n){
    if( cas > 1 ) cout <<endl;
    cout << "Case "<< cas++ <<":"<<endl;
    fw f(n+1);
    vi A(n);
    rep(i, 0, n){
      cin >> A[i];
      f.update(i+1, A[i]);
    }
    bool ok = true;
    while(ok){
      cin >> op;
      /* debug1( op ); */
      if( op[0] =='S'){
        cin >> x >>y;
        f.update(x, y-A[x-1]);
        A[x-1] = y;
      }else if( op[0]=='M'){
        cin >> x >>y;
        ll ans = f.query( y) - f.query( x-1);
        cout <<ans <<endl;
      }else{
        /* debug1( op); */
        ok = false;
      }
    }
  }
  
  
  
  
  return 0;
}
