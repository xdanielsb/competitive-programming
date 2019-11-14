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

  int q;cin >> q; int x;
  while( q--){
    int n1, n2; cin >> n1;
    ll arr1[2], arr2[2];
    rep(i, 0, 2) arr1[i] = arr2[i]= 0;
    rep(i, 0, n1){
      cin >> x;
      arr1[x%2]++;
    }
    cin >> n2;
    rep(i, 0, n2){
      cin >> x;
      arr2[x%2]++;
    }
    ll ans = arr1[0]*arr2[0] + arr1[1]*arr2[1];
    cout << ans <<endl;

  }
  
  
  return 0;
}
