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
    pos.push_back(-k-1);
    for( int i = 0; i  < n; i++){
      cin >> x;
      if( x == '1') pos.push_back( i );
    }
    pos.push_back(n+k);
    int ans = 0;
    for( int i =1; i < size(pos); i++){
      ans += max(0, (pos[i] - pos[i-1] -k -1)/(k+1));
    }
    cout << ans <<endl;
  }
  return 0;
}
