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

const int MAXN = 2e5+17;
char arr[MAXN];
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int n;
  string s;
  while( cin >>n){
    vi A(11),B(11);
    vector <bool> vis (11, true);
    rep(i, 0, n) cin >> arr[i];
    rep(i, 0, 9) cin >> A[i];
    bool in = false, first =true;
    int to, aux;

    for( int i =0; i <n; i++){
      int x = (arr[i] -'0');
      if( x >= A[x-1]) continue;
      //debug2( x, A[x-1]);
      while(i <n && x <= A[x-1]){
        arr[i] = A[x-1] +'0';
        i++;
        x = arr[i]-'0';
      }
      break;
    }
    rep(i, 0, n){
      cout << arr[i];
    }
    cout <<endl;
  }





  return 0;
}
