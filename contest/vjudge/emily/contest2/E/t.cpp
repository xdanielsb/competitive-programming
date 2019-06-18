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
typedef pair<ll,ll> ii;
typedef vector<int> vi;

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int n,k;
  while( cin >> n >> k){
  //  debug2( n, k);
    if( k > n || ( n > 1 && k ==1)){
      cout << -1 <<endl;
      continue;
    }
    if( k == 1){
      cout << 'a' <<endl;
    }else if( k == 2 ){
      rep( i, 0, n){
        if( i%2 ==0) cout << 'a';
        else cout << 'b';
      }
      cout <<endl;
    }else{
      rep( i, 0, n-(k-2)){
        if( i %2 == 0){
          cout << 'a';
        }else{
          cout << 'b';
        }
      }
      char x = 'c'; int j= 0;
      rep( i, n-(k-2), n){
        cout << char(x+j);
        j++;
        if( j > 26) j = 0;
      }
      cout <<endl;
    }
  }

  return 0;
}
