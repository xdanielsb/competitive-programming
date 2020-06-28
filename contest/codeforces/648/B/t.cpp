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

const int maxn = 503+ 12;
int a[maxn], b[maxn];

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin)) 
    cerr << "no file..."<<endl;
#endif
  
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    bool ok = false;
    for( int i = 0; i < n; i++) {
      cin >> a[i];
      if( i == 0) ok = true;
      if (i > 0) ok &= a[i] >= a[i-1];
    }
    int ones = 0, zeros = 0;
    for( int i = 0; i < n; i++) {
      cin >> b[i];
      if( b[i]) ones++;
      else zeros++;
    }

    if( ok || (zeros > 0 && ones > 0)){
      cout <<"Yes\n"; 
    }else{
      cout <<"No\n";
    }
  }
  return 0;
}
