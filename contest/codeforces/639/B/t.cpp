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

ll numTriangles(ll level){
  return 3*level*1ll*(level+1)/2 - level;
}

ll findMax( ll n ){
  ll l=1,r =1e9;
  while( l <= r){
    ll mid = (l+r)>>1;
    ll sum = numTriangles(mid);
    if( sum == n ) return mid;
    if( sum > n){
      r = mid-1;
    }else{
      l = mid+1;
    }
  }
  return l-1;
}


int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int t;
  cin >>t;
  while(t--){
    ll n ;
    cin >>n;
    if( n < 1){
      cout <<0 <<endl;
      continue;
    }
    int ans =0;
    /* debug1(n); */
    while( n > 1){
      ll can = findMax( n);
      n-= numTriangles(can);
      ans++;
    }
    cout << ans <<endl;
  }
}

