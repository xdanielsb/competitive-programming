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

  int t; 
  cin >> t; 
  int arr[3];
  while( t-- ){
    int ans = 0;
    rep(i , 0, 3){ 
      cin >> arr[ i ];
      if( arr[i]){
        ans++;
        arr[i]--;
      }
    }
    if( arr[0] > 0 && arr[1] > 0 ){ // 3
      ans++;
      arr[0]--; arr[1]--;
    }

    if( arr[1] > 0 && arr[2] > 0 ){ // 6 
      ans++;
      arr[1]--; arr[2]--;
    }

    if( arr[0] > 0 && arr[2] > 0 ){ //5
      ans++;
      arr[0]--; arr[2]--;
    }

    if( arr[0] && arr[1] && arr[2])
      ans++;

   
    cout << ans <<endl;
  }

  return 0;
}
