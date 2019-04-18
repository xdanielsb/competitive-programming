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
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

bool cmp( const ii a, const ii b){
  return a.S - a.F  < b.S - b.F;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  int n;
  while( cin >>n){
    vector < ii >A(n);
    rep(i, 0, n) cin >>A[i].F >>A[i].S;
    sort( all( A ), cmp);

    ll ans =0;
    rep( i, 0, n){
      ans += A[i].F*i + A[i].S*(n-i-1);;
    }
    cout <<ans <<endl;
  }

  return 0;
}
