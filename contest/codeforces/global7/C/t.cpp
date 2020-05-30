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
const int mod = 998244353;
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif

  int n, k, x;
  while( cin >> n >> k){
    priority_queue<ii> pq;
    rep(i, 0, n){
      cin >> x;
      pq.push({-x, i});
      if(size(pq) > k) pq.pop();
    }
    ll sum = 0;
    vector< int > pos;
    while(!pq.empty()){
      ii t = pq.top(); pq.pop();
      sum += (-t.F);
      pos.PB(t.S);
    }

    sort(all(pos));

    ll ans = 1ll;
    rep(i, 1, size(pos)){
      ll diff = pos[i] - pos[i-1];
      ans = ( ans * 1ll * diff);
      ans %= mod;
    }
    cout << sum << " " << ans <<endl;
  }
  return 0;
}
