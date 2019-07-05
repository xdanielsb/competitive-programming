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

int compute( string s ){
  int n = size( s);
  int i = 1, mn = 0, step =0;
  s = s+s;
  while( i <n  && mn +step+1 < n){
    if( s[i+step] == s[mn+step]){
      step++;
    }else if( s[ mn+step] < s[i+step]){
      i = i+step+1;
      step=0;
    }else{
      mn = max( i, mn+step+1);
      i = mn+1;
      step = 0;
    }
  }

  return mn+1;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int n; string s;
  cin >>n ;
  while( n--){
    cin >> s;
    int ans = compute ( s );
    cout << ans << endl;
  }
  
  return 0;
}
