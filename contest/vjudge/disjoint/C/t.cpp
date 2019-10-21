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

int diff( const string &a, const string &b){
  int res =0;
  rep(i, 0, 4){
    int c1 = a[i]-'0', b1 = b[i] -'0';
    int com1 = abs(c1-b1);
    res += min( com1, 10 - com1);
  }
  //cout << a << " " << b << " " << res <<endl;
  return res;
}

struct union_find{
  vi v;
  union_find( int n): v(n,-1){}
  union_find(){}
  bool join( int a, int b){
    int fa = find(a), fb = find(b);
    if( fa == fb) return false;
    if( v[fb] > v[fa]) swap( fa, fb);
    v[fa] += v[fb];
    v[fb] = fa;
    return true;
  }
  int find( int a ) {
    return v[a] < 0 ? a : v[a] = find( v[a]);
  }
};

int main(){
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int q; cin >> q; int n;
  string key, mkey;
  string zero = "0000";  
  while( q--){
      int mk = 1231231, idx=0; 

      vector< pair < int , ii >> forest;
      cin >> n; vector< string > keys;
      rep(i, 0, n){
          cin >> key; keys.PB( key );
          int aux = diff( zero, key);
          if( aux < mk){
              mkey = key;
              idx = i;
              mk = aux;
          }
      }

      rep(i, 0, size(keys)){
        rep(j, i+1, size(keys)){
          forest.PB( { diff( keys[i],keys[j]), {i, j}});
        }
      }

      if( mk ){
        forest.PB( { mk, {idx, n}});
        keys.PB( zero );
      }
     // debug1( size( forest ));
      union_find uf( size( keys ));
      int ans = 0;
      sort( all ( forest ));

      rep(i , 0, size( forest )){
        int x = forest[i].S.F, y = forest[i].S.S;
        if( uf.join( x, y )){
          ans += forest[i].F;
        }
       // cout << keys[x] << " " << keys[y] << " " << forest[i].F <<endl;
       // cout << x << " " << y << " " << forest[i].F <<endl;
      }
      cout << ans <<endl;
  }
  return 0;
}
