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
 
  int s, t, n;
  while( cin >> s >> t >> n ){
    vi delay(n+1), bus(n), inter(n);
    rep(i, 0, n+1) cin >> delay[i];
    rep(i, 0, n) cin >> bus[t];
    rep(i, 0, n) cin >> inter[i];

    int ta = 0;
    rep(i, 0, n){
      ta += delay[i];
      ta += ( ((ta+inter[i]-1)/inter[i])*inter[i] - ta);//time to wait for the next bus_i
      ta += bus[i];
    }
    ta += delay[n];
    if( ta <= t){
      cout << "yes" <<endl;
    }else{
      cout << "no" <<endl;
    }

  }
  
  
  
  return 0;
}
