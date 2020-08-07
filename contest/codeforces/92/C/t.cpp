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

int max_match(int a , int b, const string &x){
  int ans = 0;
  for( int i = 0; i < size(x); i++){
    if( (x[i]-'0') == a){
      ans++;
      swap(a,b);
    }
  }
  if( a!=b && ans%2 == 1) ans--;
  return ans;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int t;
  cin >> t;
  while(t--){
    string x;
    cin >> x;
    int n = size(x);
    int ans = 0;
    for( int i = 0; i < 10; i++){
      for( int j = 0; j < 10; j++){
        ans = max( ans, max_match(i, j, x));
      }
    }
    cout << n - ans << endl;
  }
  return 0;
}













