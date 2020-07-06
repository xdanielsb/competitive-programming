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
    int n;
    cin >> n;
    vector< int > a(n);
    for( int i = 0; i < n; i++){
      cin >> a[i];
    }
    vector<int> ans;
    while(n){
      vector< bool > is(n, false);
      for( int i = 0; i < n; i++){
        if( a[i] < n)
          is[a[i]] = true;
      }
      int mex = 0;
      while(mex < n && is[mex]) mex++;
      if( mex==n){
        ans.push_back(mex-1);
        a[mex-1] = mex-1;
        n--;
      }else{
        a[mex] = mex;
        ans.push_back(mex);
      }
    }
    cout<< size(ans) <<endl;
    for( int x: ans) cout << (x+1) << " ";cout <<endl;
  }
  
  return 0;
}
