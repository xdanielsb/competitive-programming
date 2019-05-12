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
typedef vector<ll> vi;

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int n,z;  
  while( cin >> n >> z){
    vi A( n ); rep( i ,0 ,n) cin >> A[i];
    sort( A.begin(), A.end());
    vector<bool > vis(n, false);
    int i =0, j = n/2, ans = 0;
    while( 1 ){
      while( vis[i] ) i++;
      while(j<n && vis[j]) j++;

      if(  j>=n ) break;
      
    
      if((A[ j ]-A[ i ])>=z){
        /* debug2( i, j); */
        ans++;
        vis[i] = vis[j] = true;
        i++; j++;
      }
      else{
        j++;
      }
    }
    cout <<ans <<endl;
  }
  
  return 0;
}
