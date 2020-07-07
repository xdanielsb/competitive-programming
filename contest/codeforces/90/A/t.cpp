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
  if(!freopen("in", "r" , stdin)) 
    cerr << "no file..."<<endl;
#endif
 int t;
 cin >> t;
 while(t--){
   ll a, b, c;
   cin >> a >> b >> c;

   ll ans1 =-1, ans2=-1;
   for( ll x = 1; x <= 10 && ans1==-1; x++){
     ll p1 = x * a, p2 = ( x + b - 1)/ b * c;
     if(p1 < p2) ans1 = x;
   }
   for( ll x = b; x <= b*2 && ans2 ==-1; x+=b){
     ll p1 = x * a, p2 = ( x + b - 1)/ b * c;
     if(p1 > p2) ans2 = x;
   }
   cout << ans1 << " " << ans2 <<endl;

 }
  
  return 0;
}
