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


int get( char a ,  char b){
  if( a >b ) swap(a, b);
  int a1 = b -a;
  int a2 = 'Z'-b + a-'A'+1;
  int ans = min( a1, a2);
  return ans;
}
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

 int n;
 string s;
 while( cin >> n){
   cin  >> s;
   int ans = INT_MAX;
   string to = "ACTG";
   for( int i= 0; i< n-3; i++){
     int aux =0;
     for( int j=0; j <4; j++){
       aux += get( s[i+j], to[j]);
     }
     ans = min( aux, ans);
   }
   cout << ans <<endl;
 }



  return 0;
}
