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

  int a;
  while( cin >> a){
    vector<int> bin(6, 0);
    rep(i, 0, 6){
      if( a & (1<<i))bin[5-i] = 1;
    }
    swap(bin[1], bin[5]);
    swap(bin[2], bin[3]);
    int ans = 0;
    rep(i, 0, 6)
      if(bin[5-i]) ans += 1<< i;
    cout << ans <<endl;
  }


  return 0;
}
