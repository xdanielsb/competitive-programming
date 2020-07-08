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

ll find( vector< ll > A, int l, int r){
  ll ans = 0;
  if( l < 0 || r >= size(A)) return 0;
  while( l < r ){
    swap(A[l++], A[r--]);
  }
  for( int i= 0; i < size(A); i+=2) ans +=abs(A[i]);
  return ans;
}

int dx[8] = {-2, -1, 1, 2, 0, 0, 0, 0};
int dy[8] = {0, 0,  0, 0, -2, -1, 1, 2};

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
    int n;
    cin >> n;
    vector< ll > A(n);
    for( int i = 0; i < n; i++){
      cin >> A[i];
      if( i % 2 == 0){
        A[i] *= -1;
      }
    }
    // find the limits of the maximun subsequent subarray
    int l = 0, r = 0;
    ll maxsum = A[0], cursum = A[0];
    for( int i = 0; i < n; i++){
      if(A[i] > A[i] + cursum){
        l = i;
      }
      cursum = max( cursum+A[i], A[i]);
      if( cursum > maxsum){
        r = i;
        maxsum = cursum;
      }
    }
    ll ans = find(A, l, r);
    for( int i = 0; i < 8; i++)
      ans = max(ans, find(A, l+dx[i], r+dy[i]));
    cout << ans <<endl;

  }
  
  return 0;
}
