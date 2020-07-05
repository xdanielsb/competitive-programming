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
    int n, x;
    cin >>n;
    stack< int> st;
    for( int i = 0; i < n; i++){
      cin >> x;
      if( !st.empty()){
        int lst = -1;
        while( !st.empty() && st.top() < x){
          lst = st.top();
          st.pop();
        }
        if( lst!= -1) x = lst;
        st.push(x);
      }else{
        st.push(x);
      }
    }
    if( size(st) <= 1) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}
