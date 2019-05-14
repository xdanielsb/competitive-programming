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

using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

 int t,n;
 cin >> t;
 while( t--){
  cin >>n; vi A(n);rep( i,0, n) cin >>A[i];
  sort(A.begin(),A.end());
  ll po = A[0] * 1ll* A.back();
  vector< ll > divs;
  for( ll i =2; i*1ll*i <= po; i++){
    if( po % i == 0){
      divs.push_back( i);
      if( po/i!=i)divs.push_back( po/i);
    }
  }
  sort( divs.begin(), divs.end());
  if( size(divs)!= n){
    cout << -1 <<endl;
  }else{
    bool ok = 1;
    int i =0,j =n -1;
    while( i <= j){
      if( A[i]*1ll*A[j] != po){
        ok = 0;
        break;
      }
      i++;j--;
    }
    if( ok ){
      cout << po <<endl;
    }else{
      cout << -1 <<endl;
    }
  }
 }



  return 0;
}
