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
  cin >> t;
  while(t--){
    int even = -1, odd1= -1, odd2 = -1;
    int n,x;
    cin >> n;
    for( int i = 0; i < n; i++){
      cin >> x;
      if( x%2 == 0) even = i+1;
      else{
        if( odd1 == -1) odd1 = i+1;
        else odd2 = i+1;
      }
    }
    if( even > 0){
      cout << 1 << endl;
      cout << even << endl;
    }
    else if( odd1 > 0 && odd2 > 0){
      cout << 2 <<endl;
      cout << odd1 << " " << odd2 <<endl;
    }
    else{
      cout << -1 <<endl;
    }
  }
  return 0;
}
