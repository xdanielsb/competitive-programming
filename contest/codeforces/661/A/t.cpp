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
    int n;
    cin >> n;
    vector< int > A(n);
    for( int i = 0;  i < n; i++)  cin >>A[i];
    bool ok = true;
    sort(all(A));
    for( int i = 1; i < n && ok ; i++)
      ok &= ( A[i] - A[i-1] <= 1);
    printf(ok?"YES\n":"NO\n");
  }
  return 0;
}
