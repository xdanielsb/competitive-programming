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

 int n,a,x,b,y;
 while( cin >> n >> a >> x >> b >> y){
   bool ok = false;
    while( a != x && b !=y ){
       a++; b--;
       if( a > n) a=1;
       if( b ==0  ) b = n;
       if( a == b ){
         ok = true;
         break;
       }
    }
    if( ok ) cout << "YES"<<endl;
    else cout << "NO" <<endl;
 }

  return 0;
}
