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
const int maxn = 50 + 10;

char ma[maxn][maxn];
bool vis[maxn][maxn];
bool memo[maxn][maxn];
int n, m;
int dx[4] = {-1, 1, 0 , 0};
int dy[4] = {0, 0, -1, 1};



void can( int i, int j){
  if( i < 0 || j < 0 || i >n || j> m) return ;
  if( ma[i][j] == '#' || ma[i][j] == 'B') return ;
  if(vis[i][j]) return ;
  vis[i][j] = true;
  for( int k = 0; k < 4; k++){
    can(i+dx[k], j+dy[k]);
  }
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

  while( t--){
    memset(ma, '#', sizeof(ma));
    memset(vis, false, sizeof(vis));
    memset(memo, false, sizeof(memo));
    cin >> n >>m;
    for( int i = 1; i <= n; i++){
      for( int j = 1; j <= m; j++){
        cin >> ma[i][j];
      }
    }
    bool ok = (ma[n][m]!='B');
    // check good people is not next to bad people
    for( int i = 1; i<= n && ok ; i++){
      for( int j = 1 ; j<=m && ok; j++){
        if(ma[i][j] == 'G'){
          for( int k = 0; k < 4 ; k++){
            if( ma[i+dx[k]][j+dy[k]] == 'B') ok = false;
          }
        }
      }
    }

    // close all possible outputs of bad people
    for( int i = 1; i<= n && ok; i++){
      for( int j = 1 ; j<=m; j++){
        if(ma[i][j] == 'B'){
          for( int k = 0; k < 4 ; k++){
            if( ma[i+dx[k]][j+dy[k]] == '.') ma[i+dx[k]][j+dy[k]] = '#';
          }
        }
      }
    }

    /* cout <<endl; */
    /* for( int i = 0; i<= n+1 ; i++){ */
    /*   for( int j = 0 ; j<=m+1; j++){ */
    /*     cout <<ma[i][j]; */
    /*   } */
    /*   cout <<endl; */
    /* } */
    
    //checking if is possible to go from good to the end
    //

    can(n, m);
    for( int i = 1; i<= n && ok ; i++){
      for( int j = 1 ; j<=m && ok; j++){
        if(ma[i][j] == 'G'){
          ok &= vis[i][j];
        }
      }
    }

    if( !ok){
      cout <<"No\n";
    }else{
      cout <<"Yes\n";
    }
    
  }
  
  return 0;
}
