#include <bits/stdc++.h>
#include <algorithm> 
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
  
  int n, x;
  while( cin >>n ){
    vi ans( n ), left;
    set< int > ss;
    rep(i, 0, n){
      cin >> ans[ i ];
      ss.insert( i+1);
    }
    rep(i ,0 ,n){
      ss.erase( ans[i]);
    }

    deque< int > q;
    rep(i, 0, n){
      if( ans[i] == 0){
        if( ss.count( i+1) ) q.push_front( i+1);
        else q.push_back( i+1);
      }
    }
    while( !q.empty() ){
      int t = q.front();q.pop_front();
      int aux = *ss.begin();
      if( aux == t){
        ss.erase( ss.begin());
        ans[ t-1] = *ss.begin();
        ss.erase( ss.begin());
        ss.insert( aux);
      }else{
        ans[t-1] = aux;
        ss.erase( ss.begin());
      }
    }
    for( int x: ans) cout << x<< " "; cout <<endl;
  }
  return 0;
}
