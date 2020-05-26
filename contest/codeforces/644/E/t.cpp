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
const int maxn = 55;
char ma[maxn][maxn];
bool is[maxn][maxn];
int n;
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
    cin >> n;
    bool isPossible = true;
    rep(i, 0, n){
      rep(j, 0, n){
        cin >> ma[i][j];
      }
    }

    // check the condition isPossible==true is harder, try to check always
    // which way is easier
    rep(i, 0, n-1){
      rep(j, 0, n-1){
        if( ma[i][j] == '1' && ma[i][j+1] == '0' && ma[i+1][j] == '0') isPossible = false;
      }
    }




    printf(isPossible?"Yes\n":"No\n");
  }


  return 0;
}
