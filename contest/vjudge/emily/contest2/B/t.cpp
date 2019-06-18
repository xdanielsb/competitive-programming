#include <bits/stdc++.h>
#define endl '\n'
#define debug1( x ) cout << #x << " = " <<  x << endl;
#define debug2( x, y) cout <<#x << " = " << x << " , " <<#y << " = " << y <<endl;
#define F first
#define S second
#define PB push_back
#define size( x )   ll( ( x ).size( ) )
#define endl '\n'
#define rep(i, a, b) for( __typeof(a) i =(a); i<(b);i++)
#define rept(i, a, b) for( __typeof(a) i =(a); i<=(b);i++)
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;



ll solve( ll n, ll cur, ll to ){
  if( n == 0  ) return cur == to;
  return solve(  n-1, cur+1,to)+solve(  n-1, cur-1,to);
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  string a, b;
  while( cin >> a >> b){
  //  debug2( a, b);
    ll n = size(a );
    ll mi =0, ma = 0, xi = 0, xa = 0, aux = 0;
    rep(i, 0, n){
      if( a[i]=='+') ma++;
      else mi++;
      if ( b[i]=='+'){
        xa++;
      }else if( b[i] =='-'){
        xi++;
      }else{
        aux++;
      }
    }
    cout << setprecision(10)<< fixed;
    ll diffa = ma-mi;
    ll diffb = xa-xi;
    if( aux == 0){
      if( diffa == diffb) cout << 1.0 <<endl;
      else cout << 0.0 <<endl;
    }else{
       ll ans = solve( aux, diffb, diffa);
       ld res = ans/ld(1<<aux);
       cout << res <<endl;

    }
  }
  return 0;
}
