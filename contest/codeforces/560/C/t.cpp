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

  int n;
  while( cin >>n){
    vector< char > A(n); rep(i, 0, n) cin >> A[i];
    vector< bool > vis(n, true);

    int ans =0, last=0;
    rep(i, 1, n){
    //  debug2(i , ans);
      if((i+ans)%2){
        if( A[last]==A[i]){
          ans++;
          vis[last] = false;
          last = i;
        }
      }else{
        last = i;
      }
    }
    //debug2(n,ans);
    if( ((n-ans) % 2))n--, ans++;
    cout << (ans) <<endl;
    rep(i ,0 ,n){
      if( vis[i]) cout << A[i];
    }
    cout <<endl;
  }




  return 0;
}
