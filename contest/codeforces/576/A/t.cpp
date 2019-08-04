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
  freopen("in", "r" , stdin);
#endif

 int n, x,y ;
 while( cin >> n >> x >> y){
   vi rr( n );
//   debug2( x,y );
   rep( i, 0, n ) cin >> rr[i];
   rep( i, 0, n ){
     bool ok = 1;
     for( int j= max( 0, i-x); j <  i; j++){
       if( rr[j] < rr[i]) ok = false;
     }
     for( int j = i+1; j < min( i+y+1, n); j++){
       if( rr[j] < rr[i]) ok = false;
     }
     if( ok){
       cout << (i+1) <<endl;
       break;
     }
   }
 }




  return 0;
}
