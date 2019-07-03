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
  freopen("in", "r" , stdin);
#endif


  int n;
  while(cin >>n){
    vector< char > A(n);
    map< char, int > cnt;
    set< char > diff;
    rep(i, 0, n){
      cin >>A[ i ];
      diff.insert(A[i]);
      cnt[ A[ i ] ]++;
    }
    string colors ="RGB";
    set<char> ans ;
    if( cnt['R']>=1 ){
      if(cnt['G'] >=1) ans.insert('B');
      if(cnt['B'] >=1) ans.insert('G');
    }
    if( cnt['G']>=1 ){
      if(cnt['B'] >=1) ans.insert('R');
    }

    if( cnt['R'] > 1 ){
      if(cnt['G'] >=1) ans.insert('G');
      if(cnt['B'] >=1) ans.insert('B');
    }
    if( cnt['G'] > 1 ){
      if(cnt['R'] >=1) ans.insert('R');
      if(cnt['B'] >=1) ans.insert('B');
    }
    if( cnt['B'] > 1 ){
      if(cnt['R'] >=1) ans.insert('R');
      if(cnt['G'] >=1) ans.insert('G');
    }

    //debug1( size(diff));debug1(A[0]);
    if( size(diff)==1){
      ans.insert(A[0]);
    }
    for( char x: ans){
      cout << x;
    }
    cout<< endl;


  }


  return 0;
}
