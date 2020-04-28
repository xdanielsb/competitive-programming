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

bool isSubs( string &s, string &t){
  /* debug2(s,t); */
  int i =0, j =0;
  for( ; i < size(t) && j < size( s); ){
    if( t[i] == s[j]){
      i++; j++;
    }else{
      j++;
    }
  }
  return i == size(t);
}
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif

  int t; cin >> t;
  while(t--){
    string t, ans;
    cin >> t;
    int n = size(t);
    rep(k,1, n+1){
      string s1(2*n, '0'), s2(2*n, '1');
      for(int i=0; i<2*n; i+=k){
        s1[i] = '1';
        s2[i] = '0';
      }
      if( isSubs(s1, t)){
        ans = s1;
        break;
      }
      if( isSubs(s2, t)){
        ans = s2;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
