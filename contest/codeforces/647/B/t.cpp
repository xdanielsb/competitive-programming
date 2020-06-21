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
  cin >>t;
  while(t--){
    int n, x;
    cin >> n;
    unordered_set< int>  A;
    vector< int > B(n);
    int mx = -1;
    for( int i = 0; i < n ; ++i){
      cin >> x;
      A.insert(x);
      B[i] = x;
    }

    bool ok = false; int i =0 ;
    for( i = 1; i <= 2049; i++){
      set< int > vis;
      ok = true;
      for( int j = 0; j < n; j++){
        int res = (i ^ B[j]);
        if( vis.count(res) || A.count(res) == 0) ok = false;
        vis.insert(res);
      }
      if( ok) break;
    }

    if(ok){
      cout << i <<endl;
    }else{
      cout << -1 <<endl;
    }

  }
  
  return 0;
}
