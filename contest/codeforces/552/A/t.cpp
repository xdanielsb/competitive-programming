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

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

 vector< ll > x(4);
 rep( i, 0, 4) cin >> x[i];
 sort( x.rbegin(), x.rend());

 ll all = x[0];
 rep( i, 1, 4){ // a+b
   rep( j, 1, 4){ //a +c
     if( i==j ) continue;
     rep( k, 1, 4){ //b+c
       if( k == i || k == j ) continue;
       ll c = all - x[i];
       ll b = all - x[j];
       ll a = all - x[k];
       if( a > 0 && b > 0 && c >0 && a+b+c == all){
         cout << a << " " << b  << " " <<c <<endl;
         return 0;
       }
     }
   }
 }

  return 0;
}
