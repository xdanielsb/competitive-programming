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

const int maxn = 2e5+10;
int arr[maxn];
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
    int n, x;
    cin >> n;
    memset(arr, 0, sizeof(arr));
    rep(i, 0, n){
      cin >> x;
      arr[x]++;
    }
    int ans = 1;
    int cu = 0; // current granies

    rep(i, 0, maxn){
      cu += arr[i];
      /* debug2(i, cu); */
      if( cu >= i) ans = i;
    }
    cout << ans+1  <<endl;


  }

  return 0;
}
