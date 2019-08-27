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
//  ios::sync_with_stdio( false );
//  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  int q, n;
  cin >>  q;
  while( q--){
    cin >> n;
    vi C(n);
    int st = 0; bool ok = true;
    rep(i, 0, n) {
      cin >> C[i];
      if( C[i] == 1) st = i;
    }
    if( n == 1){
      cout << "YES" <<endl; continue;
    }
    int diff = C[(st+1) % n] - C[st];
    int diff2 = C[(st-1+n) % n] - C[st];
    if( diff == 1 ){
      rep(i, 0, n-1){
        int aux = C[(i+st+1) %n] - C[(st+i)%n];
        if( aux != diff || abs(aux) != 1) ok =false;
      }
    }else{
      rep(i, 0, n-1){
        int aux = C[(-i+st-1 +n) %n] - C[(st-i+n)%n];
        if( aux != diff2 || abs(aux) != 1) ok =false;
      }
    }
    printf(ok ?"YES\n":"NO\n");
  }



  return 0;
}
