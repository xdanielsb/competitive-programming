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


bool check( vector<string> &vs, string &cmp){
  int diff = 0;
  rep(i, 0, size(vs)){
    diff = 0;
    rep(j, 0, size(cmp)) diff+= cmp[j] != vs[i][j];
    if( diff > 1){
      return false;
    }
  }
  return true;
}
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
    int n, m;
    cin >> n>> m;
    vector< string > vs(n);
    rep(i, 0, n) cin >> vs[i];
    string ans;
    rep(i, 0, m){
      string aux = vs[0];
      for( char x ='a'; x<='z'; x++){
        aux[i] = x;
        if( check( vs, aux) ) ans = aux;
      }
    }
    if( size(ans) ){
      cout << ans <<endl;
    }else{
      cout << -1 <<endl;
    }
  }

  return 0;
}
