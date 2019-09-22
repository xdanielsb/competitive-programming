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
#define allr(x) x.rbegin(),x.rend()

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
bool cmp( ii &x, ii &y){ return x.F < y.F;}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif


  int n;
  while( cin >>n){
    vector< ii > A(n);
    vector<int> B(n);
    rep(i, 0, n){
      cin >> A[i].F;
      A[i].F *= -1;
      A[i].S = i+1;
    }
    sort(all(A));
    ll ans = 0;
    rep(i, 0, n){
      ans += i*1ll*A[i].F -1;
    }
    cout << -ans <<endl;
    rep(i, 0, n){
      cout << A[i].S;
      if( i != n-1 )cout << " ";
    }
    cout <<endl;
  }

  return 0;
}
