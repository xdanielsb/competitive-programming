#include <bits/stdc++.h>
#define endl '\n'
#define debug1( x ) cout << #x << " = " <<  x << endl;
#define debug2( x, y) cout <<#x << " = " << x << " , " <<#y << " = " << y <<endl;
#define F first
#define S second
#define pb push_back
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


  int n;
  while( cin >> n ){
    int ca = 0, cb = 0, tot =0; string ans ="";
    char x;
    rep(i, 0, n){
      cin >> x;
      if (x == 'a') ca++;
      else cb++;
      //debug2( ca, cb );
      if( i %2 == 1){
        if( ca == cb ){
          ans.pb( x );
        }else if( ca > cb){
          ans.pb('b'); tot++; cb++; ca--;
        }else{
          ans.pb('a'); tot++; cb--; ca++;
        }
      }else{
        ans.pb( x );
      }
    }
    cout << tot <<endl;
    cout << ans <<endl;
  }




  return 0;
}
