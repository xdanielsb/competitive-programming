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
 int x, y;
 while( cin >> x>> y){
   if( ( x < 0  && y < 0) || y <0) x *= -1, y*=-1;
   int dis = sqrt(x*x + y*y);
   if( fabs(dis  -sqrt(1.*x*x + y*y)) <  1e-6){
     cout << "black" <<endl;
     continue;
   }
   if( x < 0){
     if( dis % 2 == 0) cout << "white";
     else cout << "black";
   }else{
     if( dis % 2 == 0) cout << "black";
     else cout << "white";
   }
   cout <<endl;
 }


  return 0;
}
