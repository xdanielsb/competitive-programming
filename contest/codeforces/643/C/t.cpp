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

// this is TLE but easy to understand
void quadratic(){
  int a, b, c, d;
  while( cin >> a >> b >> c >> d ){
    ll ans = 0;
    for( int z = c; z <= d; z++){
      for( int y = b; y <= c; y++){
        int x = max(a, z - y + 1);
        if( x > b) continue;
        ans += b - x  + 1;
      }
    }
    cout << ans <<endl;
  }
}

ll sum( int x){
  return x *1ll* (x+1) / 2;
}

void linear(){
  int a, b, c, d;
  // a    b    c    d
  //   xi   bi   z
  while( cin >> a >> b >> c >> d ){
    ll ans = 0;
    int bi = b, xi;
    /* cout << a << " " << b << " " << c << " " << d <<endl; */
    for( int z = c; z <= d; z++){
      // find the first xi <= b
      while( (xi = z - bi + 1) > b && bi <= c){
        bi++;
      }
      if( bi > c ) break;
      if( xi < a ) xi = a;

      int midrem = c - bi;
      int cnt = xi - a;

      int l = b - xi +1;
      if( bi + cnt <= c){
        int r = l + cnt;
        ans += sum(r) - sum(l-1);

        int rem = midrem - cnt;
        int cc = (b-a+1);
        ans += cc*1ll* rem;
      }else{
        int r = l + midrem;
        ans += sum(r) - sum(l-1);
      }
    }
    cout << ans <<endl;
  }
}


int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int a, b, c, d;
  linear();
  return 0;
}
