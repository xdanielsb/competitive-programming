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


bool check( int &a, int &b, int &c){
  /* d3(a, b, c); */
  return a + b <= c;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int n;
  cin >> n;
  while(n--){
    int x;
    cin >> x;
    vector< int > A(x); 
    for( int i = 0; i < x; i++) cin >>A[i];
    sort(all(A));

    bool  flag = false;
    for( int i = 0; i < x-3 && !flag; i++){
      if( check(A[i], A[i+1], A[i+2])){
        flag = true;
        cout << A[i] << " "  << A[i+1] << " " <<A[i+2]<< endl;
      }
    }
    if(!flag) cout << -1 <<endl;
  }
  return 0;
}
