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
  int t ;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vi ans(n);
    priority_queue< tuple<int, int, int>> pq;
    pq.push({n, 0, n});
    int cnt = 1;
    while(!pq.empty()){
      ll s, l, r, mid;
      tie(s, l, r) = pq.top(); pq.pop();
      mid = (l+r)/2;
      ans[mid] = cnt++;
      if( l < mid)
        pq.push({mid-l+1, l, mid});
      if( mid+1 <   r)
        pq.push({r-(mid+1)+1, mid+1, r});
    }

    rep(i, 0, n) cout << ans[n-i-1] << " ";
    cout <<endl;

  }

  return 0;
}
