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

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vi A(n);
    map<int, int >f;
    rep(i, 0, n){
      cin >> A[i];
      f[A[i]]++;
    }
    sort(all(A));

    int l=0, r =n-1;
    vi ans(n); int pos = n-1;
    while( pos >= 0){
      ans[pos--] = A[l++];
      if( pos < 0) break;
      ans[pos--] = A[r--];
    }
    rep(i, 0, n) cout << ans[i] << " ";cout <<endl;
  }
  return 0;
}
