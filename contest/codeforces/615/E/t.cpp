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

int n,m;

int solveCol( int col, vector<vi> &A){
   int minus_one = 0, ans= n;
   map<int, int > rightPos;
   map<int, int > cnt;
   rep(row,0,n){
     rightPos[row*m + col] = row;
   }  
   int shift= -1;
   
   rep(row, 0,n){
    int nshift;
    if( rightPos.find( A[row][col]) != rightPos.end()){
     nshift = (n - (rightPos[ A[row][col] ] - row + n)%n ) %n;
     cnt[nshift]++;
     ans  = min(ans, n- cnt[nshift] + nshift);
    }
   }
  return ans; 
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin)) 
    cerr << "no file..."<<endl;
#endif
  while(cin >> n>> m){
    vector< vi > A(n, vector<int>(m));
    rep(i,0 , n){
      rep(j,0, m){
        cin >> A[i][j]; A[i][j]--;
      }
    }
    ll ans = 0;
    rep(i, 0, m){
      ans+= solveCol( i, A );
    }
    cout << ans << endl;
  }
  
  return 0;
}
