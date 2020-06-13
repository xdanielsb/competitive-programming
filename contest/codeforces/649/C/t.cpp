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
  int n;
  while( cin >>n ){

    vector< int > a(n+1), ans(n+1, -1);
    vector< bool> taken(n+1, false);
    for( int i = 1; i<=n ; i++) cin >>a[i];
    for( int i = 1; i<=n ; i++){
      if(a[i] != a[i-1]){
        ans[i] = a[i-1];
        taken[ ans[i]] = true;
      }
    }
    taken[a[n]]=true;
    int v = 0;
    for( int i = 1; i<=n ; i++){
      while( taken[v])v++;
      if(ans[i] == -1){
        ans[i] = v;
        taken[v] = true;
      }
    }

    for( int i = 1; i <=n; i++){
      cout << ans[i] << " ";
    }
    cout <<endl;

  }
}
