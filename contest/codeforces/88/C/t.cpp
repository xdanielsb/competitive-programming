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
typedef long double ld;
ld h, c, t;
ld find(  ll k){
  ld ans = (k+1)*1.*h +  k*c;
  ans /= (2.*k+1.);
  return ans;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int ti; cin >>ti ;
  while(ti--){
    cin >> h >> c >> t;
    if( t >= h){
      cout << 1 <<endl;
      continue;
    }
    if( t <= (h+c)/2){
      cout << 2 << endl;
      continue;
    }
    ll low = 1, high = 1e18;
    ll pos = 0;
    while( low <= high){
      ll mid = (low + high)  >> 1;
      ld aux = find( mid );
      if( aux >= t ){
        pos = mid;
        low = mid+1;
      }else{
        high = mid-1;
      }
    }
    ld ans = 1e18, idx = pos;
    for( ll i = pos - 10; i < pos + 10; i++){
      if( fabs(t-find(i)) < ans){
        idx = i;
        ans = fabs(t-find(i));
      }
    }
    cout << (idx*2+1) << endl;
  }


  return 0;
}
