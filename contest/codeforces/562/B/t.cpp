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


const int MAXN = 3e5+13;

int a[MAXN], b[MAXN];

bool check( vector< ii> &A,  int x){
  vi el;
  int i =0;
  for(; i < size(A); i++){
    if( A[i].F == x || A[i].S == x) continue;
    el.PB( i);
  }
  if( size(el) == 0 )return true;
  unordered_map< int, int > cnt;
  for( int e: el){
    cnt[A[e].F]++; cnt[A[e].S]++;
    if( cnt[A[e].F] == size(el) || cnt[A[e].S]== size(el)) return true;
  }
  return false;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

 int n, m, x,y;
 while( cin >> n >> m){
   vector< ii > A(m);
   rep(i, 0, m){
     cin >> A[i].F >>A[i].S;
   }
   if( check(A, A[0].F ) || check(A, A[0].S) ){
     cout << "YES" <<endl;
   }else{
     cout << "NO" <<endl;
   }



 }




  return 0;
}
