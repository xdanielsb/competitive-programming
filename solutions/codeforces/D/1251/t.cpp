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
typedef pair<ll,ll> ii;
typedef vector<int> vi;

ll n, s;


bool check( int m, vector< ii > &A){
  ll min = (size( A ) +1 ) / 2;
  ll sum =0;
  vector< ii > left;
  for( ii &a: A){
     if( m > a.S){
        sum+= a.F; 
     }else if( m <= a.F){
        sum += a.F;
        min--;
     }else{
        left.PB( a );
     }
  }
 
  for( int i = size( left )-1; i >= 0; i--){
    if( min > 0  ){
      sum += m; min--;
    }else{
      sum += left[i].F;
    }
  }
 //  debug2( m, sum); cout << "\t" << s << " " << min << endl; 
  return sum <= s && min <=0;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
 
  int q; cin >> q; 
  while ( q--){
      cin >> n >> s;
      vector< ii > A( n );
      rep( i , 0, n ) cin >> A[ i ].F >> A[ i ].S;
      sort( all ( A ) );
      ll l = 0, r = 1e9;
      while( l <= r){
        ll mid = ( l + r ) / 2;
        if( check( mid, A )){
           l = mid + 1;
        }else{
           r = mid - 1;
        }
      }
      cout << l-1 <<endl;
  }
  
  
  
  return 0;
}
