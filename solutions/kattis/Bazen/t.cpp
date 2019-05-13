
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
typedef  double lf;

void sol( lf x1, lf y1, lf &x2, lf &y2){
  lf total = 250*250/2;
  if( x1 == 0){
    if( y1 >= 125) y2 =0 , x2 = total/y1;
    else x2 = total/(250-y1), y2 = 250 - x2;
  }else if( y1 == 0){
    if( x1 > 125) x2 =0, y2 = total/x1;
    else y2 = total/(250-x1), x2 = 250 - y2; 
  }else{
    if( x1 >= 125) x2=0, y2 = 250- total/x1;
    else y2 = 0, x2 = 250-total/y1;
  }
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
 lf x1, y1, x2, y2;
  while( cin >> x1 >> y1){
    sol( x1, y1, x2, y2);
	  cout << setprecision(2) << fixed;
    cout << x2 << " " << y2 <<endl;
  }
  return 0;
}

