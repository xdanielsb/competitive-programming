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


void sol( ll n){
  ll real = n;
  vector< ll > divs;
  for( ll i = 2; i * 1ll * i <=n && size(divs) < 5 ; i++){
    while( n % i == 0){
      divs.push_back(i); n/=i;
    }
  }
  if( n > 1){
    divs.push_back(n);
  }
  set < ll > ans;
  vi  an;
  for( int i= 0; i< size(divs) && size(ans) < 2 ; i++){
    ll num = divs[i];
    if( ans.count(num) == 0){
      ans.insert(num);
      an.PB(num);
    }else{
      i++;
      for( ; i < size(divs) && ans.count(num); i++){
        num *=  divs[i];
      }
      if( ans.count(num) == 0) ans.insert(num), an.PB(num);
    }
  }
  ll n3;
  if( size( an) >= 2 ){
   n3 = real/(an[0]*an[1]);
   if( n3 > 1 ){
    ans.insert(n3); 
    an.PB(n3);
   }
  }
  if( size(ans) >= 3){
    cout << "YES" <<endl;
    rep(i,0,3) cout << an[i] << " "; cout <<endl;
  }else{
    cout << "NO" <<endl;
  }
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
  while( t--){
    ll n ; cin >> n; 
    sol( n );
  }
  return 0;
}
