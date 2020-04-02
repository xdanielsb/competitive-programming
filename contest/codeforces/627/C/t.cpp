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

  int t; cin >>t;
  while(t--){
    string s; cin  >>s;
    int n = size(s);
    vi A(n); 
    int ans = 0;
    rep(i, 0, n){
      if( s[i] == 'L'){
        A[i] = i >0?A[i-1]+1:1;
        ans = max(ans, A[i]);
      }
    }
    cout << (ans+1) <<endl;
  }
  
  
  return 0;
}
