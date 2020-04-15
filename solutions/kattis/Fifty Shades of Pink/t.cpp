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

bool has( string a, string b){
  for( int i= 0; i < size(a)-size(b)+1; i++){
    bool is = true;
    for (int j =0; j < size(b);j++){
      if( tolower(a[i+j]) != tolower(b[j])) is  = false;
    }
    if (is ) return true;
  }
  return false;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
    
  int t;

  while(cin >>t){
    int ans=0;
  string pat1 = "pink", pat2="rose";
  while( t--){
    string s; cin >> s; 
    if( has(s, pat1) || has(s, pat2)) ans++;
  }
  if( ans > 0)
  cout << ans <<endl;
  else 
    cout <<"I must watch Star Wars with my daughter"<<endl;
  }
  
  
  return 0;
}
