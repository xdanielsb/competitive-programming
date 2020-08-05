#include <bits/stdc++.h>
#define endl '\n'
#define d(x) cout <<#x << " = " << x << ", ";
#define d1( x ) d(x); cout <<endl;
#define d2( x, y ) d(x); d(y); cout <<endl;
#define d3( x, y, z ) d(x); d(y); d(z); cout <<endl;
#define F first
#define S second
#define PB push_back
#define size( x )   int( ( x ).size( ) )
#define endl '\n'
#define all(x) x.begin(),x.end()

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

  int test;
  cin >> test;
  while(test--){
    int n, k, z;
    cin >> n >> k >> z;

    vector<int> arr(n);
    for( int i = 0; i < n; i++) cin >> arr[i];

    int ans = 0;
    for( int i = 0; i<= z; i++){
      int until = k - 2*i;
      if( until < 0 ) continue;
      int mx = 0, sum =0;
      for( int j = 0; j <= until; j++) {
        sum += arr[j];
      }
      for( int j = 0; j <= until; j++) {
        if(j >= n) continue;
        mx = max(mx, arr[j] + arr[j+1]);
      }
      ans = max( ans, sum + mx * i);
    }
    cout << ans <<endl;
  }
 
  return 0;
}
