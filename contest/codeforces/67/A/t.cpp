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
  freopen("in", "r" , stdin);
#endif

 ll n , s, t; int cas; cin >>cas;
 while( cas--){
  cin >> n >> s >>t;
  ll it = (n-s-t);
  if(it < 0){
    cout << max(s+it, t+it)+1 << endl;
  }else if( it == 0){
    cout << max(s,t)+1<<endl;
  }else{
    cerr << "upps"<<endl;
  }
 }

  return 0;
}
