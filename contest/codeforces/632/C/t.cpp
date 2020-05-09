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

  int n;
  while(cin >> n){
    ll num, ans =0, sum = 0, left=0;
    map<ll,ll> pref; //prefix,(sum, cnt)
    pref[0] = 0;
    rep(i, 1, n+1){
      cin >> num;
      sum += num;
      if( pref.count( sum)){
        left = max(left, 1+ pref[sum]);
      }
      ans += i - left ;
      pref[sum] = i;
    }
    cout << ans <<endl;


  }

  return 0;
}
