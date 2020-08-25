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

const int maxn = 200;
int n, m;
int a[maxn];
int b[maxn];
bool check( int x){
  for( int j = 0; j < n; j++){
    bool ok = false;
    for( int k = 0; k < m && !ok; k++){
      if( (x | (a[j]&b[k])) == x ) ok = true;
    }
    if( !ok) return false;
  }
  return true;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  while( cin >> n >> m){
    for( int i = 0 ; i < n ; i++) cin >> a[i];
    for( int i = 0 ; i < m ; i++) cin >> b[i];
    for( int i = 0; i < 2e9; i++){
      if( check( i ) ){
        cout << i << endl;
        break;
      }
    }
  }
 
  return 0;
}
