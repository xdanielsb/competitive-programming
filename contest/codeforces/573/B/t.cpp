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
//  ios::sync_with_stdio( false );
//  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif


 int q, n; cin  >>q;
 while( q-- ){
   cin >> n;
   vi C(n*4);
   map< int, int > cnt;
   rep(i, 0, n*4){
     cin >> C[i];
     cnt[C[i]]++;
   }
   sort( all(C));
   int mul = C[0]*C.back();
   //debug1( mul);
   bool ok = true;

   for( ii y: cnt){
  //   debug2( y.F, y.S);
     if( y.S % 2){
       ok = false;
       break;
     }
   }

   if( ok){
     for( int i =0,j = 4*n-1; i < j ; i++,j--){
       if(C[i]*C[j] != mul){
         ok = false;
         break;
       }
     }
   }
   printf(ok?"YES\n":"NO\n");

 }




  return 0;
}
