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
 int ca = 1;
 while(t--){
   cout << "Case " <<ca++ << ": ";
   int n, lst,x;
   cin >> n;
   int high = 0, low = 0;
   cin >> lst;
   for( int i = 0; i< n-1; i++){
     cin >> x;
     if( x > lst) high++;
     else if( x < lst) low++;
     lst = x;
   }
   cout << high << " " << low <<endl;

 }
  
  return 0;
}
