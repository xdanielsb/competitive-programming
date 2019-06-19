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

const int MAXN = 1e5;
int arr[ MAXN];

void init(  int n ){
  rept( i,1 ,n) arr[i] = -1;
}
int find( int a){
  if( arr[a] < 0) return a;
  return arr[a] = find ( arr[a]);
}
int unite( int a , int b){
  int ya = find(a), yb = find(b);
  if( ya == yb ) return 0;
  if( arr[yb] > arr[ya]) swap( ya, yb);
  arr[ ya ] += arr[ yb ];
  arr[ yb ] = ya;
  return 1;
}


int main(){
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int n;cin >> n;
    vector<int> A(n+1);
    rept( i, 1, n) cin >>A[i];
    init( n );
    rept( i,1,n) unite(i, A[i]);
    unordered_set< int > ss;
    rept( i, 1,n ){
      ss.insert( find( i ));
    }
    cout << size( ss ) << endl;
  
}
