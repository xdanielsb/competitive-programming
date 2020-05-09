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
  while(t--){
    ll n;
    cin >>n;
    vi A(n);
    rep(i,0 , n) cin >> A[i];

    ll a=0, b =0, m=0;
    ll l = 0, r=n-1;
    int turn=0;
    ll last = 0;
    while( l <= r){
      ll cur = 0;
      if( turn == 0){
        while(l <= r && cur <= last){
          cur += A[l++];
        }
        a+= cur;
      }else {
        while( l <= r && cur <= last){
          cur +=A[r--];
        }
        b+= cur;
      }
      m++;
      last = cur;
      turn ^= 1;
    }

    cout << m << " " << a << " " << b <<endl;
  }
  return 0;
}
