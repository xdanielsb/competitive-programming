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
  cin >> t ;
  while(t--){
    int n, k;
    cin >> n >> k;
    vector< int > pos;
    char x;
    for( int i = 0; i  < n; i++){
      cin >> x;
      if( x == '1') pos.push_back( i );
    }
    if( size(pos) == 0){
      cout << ((n+k)/(k+1)) <<endl;
      continue;
    }
    int ans = 0;
    //beginning of string
    if( pos[0]-k > 0){
      int len = pos[0] - 1 - k;
      if( len >= 0){
        ans+= 1+ (len)/(k+1);
      }
    }
    //middle of string
    for( int i = 1; i < size(pos); i++){
      int len = pos[i] - pos[i-1] -1 - 2*k;
      if( len >= 0){
        ans+= 1+ (len-1)/(k+1);
      }
    }
    //end of string
    if( pos.back() != n-1){
      int len = n - 1- pos.back() - k -1;
      if( len >= 0){
        ans+= 1+ (len)/(k+1);
      }
    }
    cout << ans <<endl;
  }
  return 0;
}
