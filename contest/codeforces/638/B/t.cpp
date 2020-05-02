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
  int t;cin >>t;
  while(t--){
    ll n, m;
    cin >> n >>m;
    set < int >diff;
    vi A(n);
    rep(i, 0, n){
      cin >> A[i];
      diff.insert(A[i]);
    }
    if( size(diff) > m){
      cout << -1 <<endl;
      continue;
    }
    for( int i=1; i<=n && size(diff) < m ;i++){
      diff.insert(i);
    }

    vi ans;
    for( int x: diff) {
      ans.PB(x);
    }
    for( int i= 1, j=size(ans); i  <n; j++){
      if( ans[j-m] != A[i]){
        ans.PB(ans[j-m]);
      }else{
        ans.PB(A[i++]);
      }
    }
    cout << size(ans) <<endl;
    for(int x: ans) cout << x << " ";cout <<endl;


  }

  return 0;
}
