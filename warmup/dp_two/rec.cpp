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

const int maxn = 30;
int ma[maxn][maxn];
int memo[maxn][maxn];
int cnt[maxn][maxn];

int n, m; // number of rows, number of cols
int best( int row, int col){
  if( row > n || col > m )
    return 1e9;
  int &ans = memo[row][col];
  if(~ans) return ans;
  if( row == n && col == m)
    return ans = ma[row][col];
  return ans = ma[row][col] + min( best(row+1, col), best(row, col+1));
}

vector < int > path;
void build( int row, int col, int x ){
  if( row > n  || col > m ) return;
  path.push_back( ma[row][col]);
  if( row == n && col  == m){
    return;
  }
  if( memo[row+1][col] == x-ma[row][col])
    build(row+1, col, x-ma[row][col]);
  else
    build(row, col+1, x-ma[row][col]);
}

int ways( int row, int col, int x){
  if(row > n || col > m ) return 0;
  int &ans = cnt[row][col];
  if(~ans) return ans;
  ans =0;

  if( row == n && col == m) return ans = 1;
  x -= ma[row][col];
  if( memo[row+1][col] == x)
    ans += ways(row+1, col,x );
  if( memo[row][col+1] == x)
    ans += ways(row, col+1,x);
  return ans;
}


// build k path
vector<char> pathk;
void buildk( int row, int col, int k){
  if(row > n || col > m ) return ;
  if( row == n && col == m) return;
  if( ways(row+1,col,0) >= k ){
    pathk.push_back('D');
    buildk(row+1, col,  k);
    return;
  }
  k-= ways(row+1, col, 0);
  if ( k <= ways(row, col+1, 0)){
    pathk.push_back('R');
    buildk( row, col+1,  k);
  }
}




int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  while( cin >> n >> m){
    memset(memo, -1, sizeof( memo ));
    memset(cnt, -1, sizeof( cnt ));
    for( int r = 1;  r <=n ; r++){
      for( int c = 1; c <= m; c++){
        cin >> ma[r][c];
      }
    }
    int ans = best(1, 1);
    cout << ans <<endl;
    // build path
    build(1,1, ans);
    for( int &x: path) cout << x << " "; cout <<endl;
    // looking for the number of ways
    int num_ways  = ways(1, 1, ans);
    cout << num_ways <<endl;
    for( int r = 1;  r <=n ; r++){
      for( int c = 1; c <= m; c++){

        cout << cnt[r][c] << "\t";
      }
      cout <<endl;
    }

    for( int i = 1; i <= num_ways; i++){
      debug1(i);
      pathk.clear();
      if( i > num_ways){
        cout << "Impossible \n";continue;
      }
      buildk(1,1,i);
      for( char c: pathk){
        cout << c << " " ;
      }
      cout <<endl;
    }

  }
  return 0;
}
