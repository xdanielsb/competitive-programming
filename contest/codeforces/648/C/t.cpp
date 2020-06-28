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

const int maxn =  2e5 + 10;
int a[maxn];

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin)) 
    cerr << "no file..."<<endl;
#endif

  int n,x;
  while( cin >> n){
      
    for( int i = 0; i < n; i++){
      cin >> x;
      a[x] = i;
    }

    map< int, int > mx; // storage the shifts 
                        // to be in the right position
    int ans =0;
    for ( int i = 0; i < n; i++){
      cin >> x;
      int shifts =  (a[x]-i+n)%n;
      mx[shifts]++;
      ans= max( mx[shifts], ans);
    }
    cout << ans <<endl;
  }
  
  
  return 0;
}
// this code is amazing
