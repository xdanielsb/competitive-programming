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


const int MAXN = 2e5+20;
int T[26][MAXN];

int n;

inline void build( ){
  rep(j, 0, 26){
    for( int i = n-1; i > 0; i--){
      T[j][i] = T[j][i << 1] + T[j][i << 1 |1];
    }
  }
}

inline void update( int i, int x, int y){
  for( T[ i ][ x += n ] = y; x > 1; x >>= 1 ){
    T[ i ][ x >> 1 ] = T[i][x] + T[i][x^1];
  }
}

inline int query( int i ,int l , int r){
  int res = 0;
  for ( l+= n, r+= n; l <r ; l>>=1, r>>=1){
    if( l & 1 ) res += T[i][l++];
    if( r & 1 ) res += T[i][--r];
  }
  return res >= 1;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

 string w;
 while( cin >> w ){
  n = size( w );
  rep(i, 0, n) {
      T[w[i] - 'a'][ i + n] = 1;
  }

  build();

  int q; cin >>q;
  int l, r, p, t;
  char c;
  while( q--){
    cin >> t; 
    if( t == 1){
      cin >> p >> c;
      p--;
      update( w[p] -'a', p, 0);
      w[ p ] = c;
      update( w[p] -'a', p, 1);
    }else{
      cin >> l >> r;
      int ans = 0;
      l--;
      rep( i,0 , 26){
        ans += query(i, l, r);
      }
      cout << ans << endl;
    }
  }
 }
  return 0;
}
