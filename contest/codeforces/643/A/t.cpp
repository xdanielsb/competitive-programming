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

ll change( ll n){
  ll mi= 9, ma =-1;
  ll ori = n;
  while( n > 0){
    mi = min(mi, n%10);
    ma = max(ma, n%10);
    n/=10;
  }
  return ori + mi*ma;
}

ll find( ll n, ll k){
  k--;
  while(k--){
    ll aux = change(n);
    if( aux == n) break;
    n = aux;
  }
  return n;
}
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
    ll n, k;

    cin >> n >>k;
    ll ans = find(n, k);
    cout << ans << endl;

  }

  return 0;
}
