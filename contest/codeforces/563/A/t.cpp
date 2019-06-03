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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  int n;
  while( cin >>n ){
    vi A(2*n); rep(i, 0,2*n) cin >> A[i];
    sort( A.begin(),A.end());
    int l = 0, r = 2*n-1;
    ll s1=0, s2=0;
    for( int i =0; i < n; i++)  s1+=A[i];
    for( int j = n; j<2*n; j++)  s2 +=A[j];
    if( s1!=s2)for( int x: A)cout << x <<" ";
    else cout <<-1;
    cout <<endl;
  }
  return 0;
}
