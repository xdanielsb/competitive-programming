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
typedef vector<int> vi;

int main(){

#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  
  int n;
  while( cin >> n ){
    vi A(n); rep( i, 0, n) cin >> A[i];
    int ans =0; bool ok = 1;
    rep( i, 1, n){
      int a = A[i-1], b = A[i];
      if( min(a,b)==2 && max(a,b) ==3){
        ok = false;
        break;
      }
      else if( min( a, b) ==1, max( a,b) ==3){
        ans += 4;
      }
      else if( min( a, b) ==1, max( a,b) ==2){
        ans += 3;
      }
      if( i > 1 && A[i-2] == 3 && a == 1 && b ==2 ){
        ans--;
      }
    }

    if( ok){
      cout << "Finite" <<endl;
      cout << ans <<endl;
    }else{
      cout << "Infinite" <<endl;
    }

  }

  return 0;
}
