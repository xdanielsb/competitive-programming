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
typedef vector<ll> vi;

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin)) 
    cerr << "no file..."<<endl;
#endif
  int n, k;
  while( cin >> n >> k){
    /* cout <<"\n\n\n"; */
    vi A(n); rep(i, 0, n) cin >> A[i];
    sort(all(A));
    vi prefix(n+1, 0), suffix(n+1, 0);

    for(int i= 0; i < n; i++)
      prefix[i+1] = prefix[i] + A[i];

    for(int i=n-1; i>=0; i--)
      suffix[i] = suffix[i+1] + A[i];

    int i = 0, j= 0;
    ll ans = 1e18;
    for( ; i <n; i = j){
      int val = A[i];
      while( j < n && A[j] == val) j++;
      
      int need = k - (j - i);
      if( need <= 0){
        ans = 0; 
        break;
      }

      int before = i;
      int after = (n-j);
      ll before_cost = val *1ll* before -  prefix[i];
      ll after_cost = suffix[j] - after*1ll*val;
      
      /* printf("Interval=(%d,%d), beforec_cost =%d, after_cost=%d\n",i,j, before_cost, after_cost); */
      /* printf("before=%d, after=%d, need=%d\n", before, after, need); */
      /* debug1( val ); */

      if( before >= need)
        ans = min(ans, before_cost -(before-need));

      if( after >= need)
        ans = min(ans, after_cost - (after-need));

      ans = min( ans, after_cost + before_cost - ( after + before - need));
      
      /* debug1(ans); */
    }

    cout << ans <<endl;

  }
  
  return 0;
}
