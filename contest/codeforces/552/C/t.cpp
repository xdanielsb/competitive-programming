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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  vi g = {0,1,2,0,2,1,0};
  vi cnt ={3, 2,2 };
  ll x[3];
  while( cin >> x[0]>> x[1]>> x[2]){
    ll mi = 1e9, who, ans;
    rep( i, 0, 3){
      ll aux = (x[i]/cnt[i]);
      if( aux < mi){
        mi = aux;
        ans = aux*7;
      }
    }
    rep( i, 0, 3){
       x[i] -= mi*cnt[i];
    }
    ll tans = -1;
    rep( i, 0, 7){
      int x2[3];

      rep( k, 0,3) x2[k] = x[k];
      ll aux = ans;
      ll l = i;
      while( x2[g[l]] ){
        if( x2[g[l]] == 0) break;
        x2[g[l]]--;
        aux++;
        l += 1;
        l  = l %7;
      }
      tans = max( aux, tans);
    }
    cout << tans <<endl;
  }
  return 0;
}
