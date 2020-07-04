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
  ll v, c, t1, t2;
  while(cin >> v >> c >> t1 >> t2){
    /* cout <<endl;cout << v << " " << c << " " << t1 << " " << t2 <<endl; */
    if ( v + c < t1 + t2 ){
      cout << "No\n";
      continue;
    }
    if( min(v, c) >= t2){
      cout << "Yes\n";
      continue;
    }
    ll diff = abs(v-c);
    if( t1 < diff ){
      cout << "No\n";
      continue;
    }
    t1 -= diff;
    if( v >=c){
      v-= diff;
    }else{
      c-= diff;
    }

    ll mn = min(t1, t2);
    v-= mn;
    c-= mn;
    if( min( v, c) < t2){
      cout <<"No\n";
    }else{
      cout <<"Yes\n";
    }
  }
  
  return 0;
}
