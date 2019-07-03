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

const int MAXN = 1e5+17;

int neg[MAXN], pos[MAXN], a[MAXN];

int main(){
//  ios::sync_with_stdio( false );
//  cin.tie( nullptr );
//#ifdef LOCAL
  freopen("input.txt", "r" , stdin);
  freopen("output.txt", "w" , stdout);
//#endif

  int n, x;
  while( cin >> n){
  //  debug1(n);
    vector<int> tp(n);
    vector<int> tn(n);
    rep(i, 0, n){
      cin >> a[i];
      if( a[i] >= 0) tp[i]++;
      if( a[i] <= 0) tn[i]++;
    }
    for( int i= 1; i < n; i++){
      tp[i] += tp[i-1];
    }
    for( int i =n-2; i>=0; i--){
      tn[i] += tn[i+1];
    }
    int ans = INT_MAX;
    rep( i, 0, n){
      int tpa =0, tna =0;
      if( i+1 !=n )
      ans = min( ans, tp[i]+tn[i+1]);
    }
    cout <<ans <<endl;
  }

  return 0;
}
