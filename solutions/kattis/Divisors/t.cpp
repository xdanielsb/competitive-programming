/**
 *    author:  xdanielsb
 *    created: 2019-02-23   
**/
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
typedef pair<int, int> ii;
typedef vector<int> vi;


map< int, map<int,int>>  mem;
map<int, int> num;

void fact( int x){
  int rx = x;
  for( int i=2; i <= x; i++ ){
    while( x% i == 0){
      mem[rx][i]++;
      x /= i;
    }
  }
  if( x > 1) mem[rx][x]++;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in.c", "r" , stdin);
#endif

int n, k;

  for( int i =2 ; i<= 431; i++) fact( i );
while( cin >> n >> k){
  num.clear();

  for( int i= 2 ; i <= n; i++){
    for( ii a : mem[i]) {
        num[a.first] +=  a.second;
    }
  }
  for( int i= 2 ; i <= k; i++){
    for( ii a : mem[i]) num[a.first] -=  a.second;
  }
  for( int i= 2 ; i <= n-k; i++){
    for( ii a : mem[i]) num[a.first] -=  a.second;
  }

  ll ans = 1;
  for( ii x: num){
    if( x.second){
     //   debug2(x.first, x.second);
        ans = ans*1ll*(x.second+1);
    }
  }
  cout << ans <<endl;
}



  return 0;
}
