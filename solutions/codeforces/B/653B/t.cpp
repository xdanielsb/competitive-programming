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

map<char, vector< string> > mp;

int dfs(  string st, int k ){
  if( k == 1) return 1;
  int ans = 0;
  for( string aux: mp[ st[0] ] ){
    ans += dfs( aux, k-1);
  }
  return ans;
}
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int k, n;
  string pre; char to;
  
  while( cin >> k >> n){
    vector< string >ini;
    mp.clear();
    rep( i, 0, n){
      cin >> pre >> to ;
      mp[ to ].push_back( pre );
      if( to =='a'){
        ini.push_back( pre );
      }
    }
    int ans = 0;
    for( string &i: ini){
      ans += dfs ( i , k-1 );
    }
    cout << ans <<endl;
  }

  return 0;
}
