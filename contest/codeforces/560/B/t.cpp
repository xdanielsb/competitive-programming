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
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

int n,x;
while( cin >>n){
  vi A(n);
  rep(i, 0, n){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  int ans = 0, contest=1;
  rep( i,0, n){
    if(A[i]>= contest){
      ans++;
      contest++;
    }
  }
  cout << ans <<endl;
}




  return 0;
}
