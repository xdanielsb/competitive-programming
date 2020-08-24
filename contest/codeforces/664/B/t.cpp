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
  int n, m;
  while( cin >> n >> m){
    int r, c;
    cin >> r >> c;

    /* d2(r, c); */
    cout << r << " "<< c << endl;
    for( int i  = r-1; i >=1 ;i--)
      cout << i << " " << c << endl;
    for( int i  = r+1; i <=n; i++)
      cout << i << " " << c << endl;

    bool atEnd = true;// if the rock is at the end
    for( int j = 1; j<= m; j++){
      if( j == c) continue;
      if(atEnd){
        for( int i = n; i >=1; i--)
          cout << i << " " << j << endl;
      }else{
        for( int i = 1; i <=n; i++)
          cout << i << " " << j <<endl;
      }
      atEnd = !atEnd;
    }

  }
 
  return 0;
}
