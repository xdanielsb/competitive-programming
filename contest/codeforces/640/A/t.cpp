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
    ll n ;
    cin >>n;
    vector<ll> ans(32, 0);
    ll num =0;
    for( int i =0; i  < 30; i++){
      ans[i] = n%10;
      if(ans[i]) num++;
      n/=10;
    }
    cout << num <<endl;
    for( int i = 0; i < 32; i++){
      if( ans[i]){
        cout << ans[i];
        rep(j, 0, i) cout <<"0";
        cout << " ";
      }
    }
    cout <<endl;
  }
  return 0;
}
