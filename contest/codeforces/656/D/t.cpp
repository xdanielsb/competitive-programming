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
#define rept(i, a, b) for( __typeof(a) i =(a); i<=(b);i++)
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int n;
string s;

inline int count(int l, int r, char c){
  int ans = 0;
  for( int i = l; i <= r; i++) ans += (s[i] == c);
  return ans;
}

int find_moves(int l, int r, char c){
  /* debug2(l, r); */
  if( l == r ){
    return  s[l] != c;
  }
  int mid = ( r - l ) / 2;
  int num = ( r - l + 1 )/ 2;
  // first option
  int ml = num - count(l, l+mid, c) + find_moves(l+mid+1, r, c+1);
  int mr = find_moves(l, l+mid, c+1) + num - count(l+ mid+1, r, c);
  return min(ml, mr);
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin)) 
    cerr << "no file..."<<endl;
#endif

  int t;
  cin >> t;
  while(t--){
    cin >> n >> s;
    int ans = find_moves(0, n-1, 'a');
    cout << ans  <<endl;
  }
  
  
  return 0;
}
