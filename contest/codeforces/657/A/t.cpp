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

const string p = "abacaba";
vector< int> can;

int count( string a ){
  int ans = 0;
  for( int i = 0; i < size(a) - size(p) + 1; i++){
    bool ok = true;
    for( int j=  0; j < size(p); j++){
      ok &= a[i+j] == p[j] || a[i+j] == '?';
    }
    if( ok){
      can.push_back( i );
      ans++;
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

  int t; cin >> t;
  while(t--){
    can.clear();
    int n; cin >> n;

    string s; cin >> s;
    /* debug2(s, n); */
    int occurences = count( s );
    if( occurences == 0){
      cout << "No\n";
      continue;
    }
    bool ok = false;

    for( int i= 0; i < occurences; i++){
      string x = s;
      for( int j = can[i], k = 0; k < size(p); k++){
        x[j+k] = p[k];
      }
      for( int j = 0; j < n; j++){
        if( x[j] == '?') x[j] = 'z';
      }
      int aux = count(x);
      /* debug2( i, x); */
      if( aux == 1){
        cout <<"Yes\n";
        cout << x << endl;
        ok =true;
        break;
      }
    }
    if(!ok){
      cout << "No\n";
    }
  }
  
 
  return 0;
}
