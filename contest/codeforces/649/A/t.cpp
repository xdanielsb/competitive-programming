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
    int n, x;
    cin >> n >> x;
    vi A(n);
    ll sum = 0;
    int first = -1, last = -1;
    for( int i = 0; i < n ; i++) {
      cin >> A[i];
      sum += A[i];
      if( (A[i]%x)!=0){
        if( first == -1) first = i;
        last = i;
      }
    }

    /* debug2( first, last); */
    if( sum % x != 0){
      cout << n <<endl;
    }else if( first == -1){
      cout << -1 <<endl;
    }else{
      cout << max(n-first-1, last) <<endl;
    }

  }

  return 0;
}
