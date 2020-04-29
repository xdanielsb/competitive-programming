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

int n,k;
const int maxn = 2e5 + 10;
int S[maxn], A[maxn];
vi ans[maxn];

int check( int c, bool save = false){
  queue< ii > q;
  rep(i, 0, c) q.push(ii(0, i));

  /* debug2(c, size(q)); */
  rep(i, 0, n){
    ii t = q.front(); q.pop();
    /* debug2(A[i], S[A[i]-1]); */
    /* debug2(t.F, t.S); */
    if(t.F >= S[ A[i] -1 ]) return false;
    t.F++;
    q.push(t);
    if( save) ans[t.S].PB(A[i]);
  }
  return true;
}
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif

  while( cin >> n >> k){
    rep(i, 0, n){
      cin >> A[i];
      ans[i].clear();
    }
    rep(i, 0, k){
      cin >> S[i];
    }
    sort(A, A+n, [](int a, int b){ return a > b;});
    int l = 1, r = n;
    while( l <= r){
      int mid = (l+r)>>1;
      if(!check(mid)){
        l = mid + 1;
      }else{  //if possible reduce the  number of tests
        r = mid - 1;
      }
    }
    /* debug2(l, r+1); */
    cout << (r+1) <<endl;
    check(r+1, true);
    rep(i, 0, r+1){
      cout<< size(ans[i]) << " " ;
      for( int j: ans[i]) cout << j << " ";
      cout <<endl;
    }



  }



  return 0;
}
