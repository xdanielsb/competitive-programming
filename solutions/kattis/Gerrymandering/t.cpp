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
 
  
  int p, n; 
  int d, a ,b ;
  while( cin >> p >> n){
    int sa=0, sb= 0, total =0;
    map< int, ii > vots;
    rep(i, 0, p){
      cin >> d >> a >> b;
      total+=a+b;
      vots[d].F += a;
      vots[d].S += b;
    }
    rep(i,1, n+1){
      a = vots[i].F;
      b =vots[i].S;
      int needed = (a+b)/2 +1;
      if( a > b){
        cout << "A " << (a - needed) << " " << b <<endl;;
        sa+= (a-needed); sb+=b;
      }else{
        cout <<"B " << a << " "<< (b-needed) <<endl;
        sa+=a;
        sb+=b-needed;
      }
    }
    cout << setprecision(10) << fixed;
    double res = fabs(double( sa - sb)/total) ;
    cout <<res <<endl;
  }
  
  
  return 0;
}
