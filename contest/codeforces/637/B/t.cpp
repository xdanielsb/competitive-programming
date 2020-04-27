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

const int maxN =2e5 + 10;
int a[maxN];

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int t;cin >>t;
  while(t--){
    int n,k;cin >> n >> k;
    rep(i, 0, n) cin >> a[i];

    vi p(n, 0);
    rep(i,1,n-1){
      if( a[i-1] <a[i] && a[i+1]<a[i]){
        p[i] =1;
      }
    }

    rep(i, 1, n) p[i] += p[i-1];
    int ans = 0, l=0;
    rep(i, 0, n-k+1){
      int nbreak =  p[i+k-1] - p[i];
      if( i > 0 && p[i-1] < p[i]) nbreak--;
      if( i+k-2 > 0 && p[i+k-1] > p[i+k-2]) nbreak--;
      if(nbreak > ans){
        ans = nbreak+1;
        l = i+1;
      }
    }
    cout << ans << " " << l <<endl;

  }


  return 0;
}
