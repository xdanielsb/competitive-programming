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


// link https://codeforces.com/contest/471/problem/D
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
int const MAXN = 2e5;
ll arr[MAXN], pa[MAXN];

vi compute( int n ){
  vi p(n);
  rep( i, 1, n){
    p[i] = p[i-1];
    while( p[i] && pa[i] != pa[p[i]]){
      p[i] = p[ p[i]-1];
    }
    if( pa[i] == pa[ p[i]]){
      p[i]++;
    }
  }
  return p;
}

int matches(int n, int k  ){
  int m = 0, ans =0;
  if( k == 0) return n+1;
  vi p = compute( k  );
  /* rep( i,0 ,n) cout << arr[i] << " "; cout <<endl; */
  /* rep( i,0,k) cout << pa[i] << " "; cout <<endl; */
  rep( i, 0, n){
    while( m && arr[i] != pa[ m ]){
      m = p[ m -1];
    }
    if( arr[i] == pa[ m ]){
      m++;
    }
    if( m == k){
      ans ++;
      m = p[ m -1];
    }
  }
  return ans;
}


int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int n, k;
  while( cin >> n >> k){
    int x, last = 0; cin >> last;
    rep(i, 1, n) {
      cin >> x;
      arr[i-1] = x - last;
      last = x;
    }
    cin >> last;
    rep(i, 1, k){
      cin >> x;
      pa[i-1] = x - last;
      last = x;
    }
    int ans = matches( n-1, k-1);
    cout << ans <<endl;
  } 
  return 0;
}
