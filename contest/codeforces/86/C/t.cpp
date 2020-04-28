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

unsigned int a, b;
ll q, l, r;


int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif

  int t;
  ll ans;
  cin >>t;

  while(t--){
    cin >> a >> b>> q;
    int lcm = a * b / __gcd(a, b);
    int x=0; // number of different elements by segment
    vi s(lcm);
    rep(i, 0, lcm){
      if( i % a %b != i %b%a) x++;
      s[i] = x;
    }
    while(q--){
      cin >> l >> r; l--;
      ll ansr = r / lcm *1ll* x + s[r%lcm];
      ll ansl = l / lcm *1ll* x + s[l%lcm];
      cout << (ansr - ansl) <<" "[q==0];
    }
    cout <<endl;
  }

  return 0;
}
