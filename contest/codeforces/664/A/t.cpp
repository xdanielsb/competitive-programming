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

bool check( ll r, ll g, ll b, ll w){
  if( r < 0 || g < 0 || b < 0 ) return false;
  int s =  r%2 + g%2 + b %2;
  /* d3(r, g, b); */
  /* d1(s); */
  if(s == 0) return true;
  if(s == 1 && w%2==0) return true;
  if(s == 2) return false;
  if(s == 3) return true;
  assert(true);
  return false;
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
    ll w, r, g, b;
    cin >> r >> g >> b >> w;
    
    if( check(r, g, b, w)){
      cout <<"Yes\n";
    }else if( check( r-1, g-1, b-1, w+3)){
      cout <<"Yes\n";
    }else{
      cout <<"No\n";
    }
  }
 
  return 0;
}
