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


int solve(int n, int m, int k ){
  int mx = k;
  vi A(n); rep( i, 0, n) cin >>A[i];
  int ans = 0;
  rep( i,0 ,n){
    if( m == 0 && k == 0) break;
    if( A[i] == 0 ){
      if( k > 0){
        k--;
      }else{
        m--;
      }
    }else if(A[i]==1){
      if( k == mx){
        k--;
      }else if( m >0){
        m--;
        k++;
        k = min(mx, k);
      }else{
        k--;
      }
    }
    ans++;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  int n, m, k;
  while( cin >> n >>m >>k){
    int ans = solve(n, m,k);
    cout << ans <<endl;
  }


  return 0;
}
