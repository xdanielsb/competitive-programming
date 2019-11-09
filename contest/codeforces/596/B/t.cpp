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

const int MAXK = 1e6+10;
int cnt[MAXK];

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin)) 
    cerr << "no file..."<<endl;
#endif

  int q; cin >> q;
  int n, k, d;
  while( q--){
    cin >> n >> k >> d;
    vi A(n);
    rep(i, 0, n){
      cin >> A[i];
      cnt[A[i]] = 0;
    }
    int ans = 0;
    rep(i, 0, d) {
      cnt[A[i]]++;
      if( cnt[A[i]] == 1 ) ans++;
    }
    //debug1( ans );
    int l = 0, r = d, aux = ans;
    while( r < n){
      if(A[l] != A[r]){
        if( cnt[ A[l] ] == 1) aux--;
        if( cnt[ A[r] ] == 0) aux++;
      }
      ans = min( aux, ans);
      cnt[ A[l]]--;
      cnt[A[r]]++;
      l++, r++;
    }
    cout << ans <<endl;
  }
  
  
  return 0;
}
