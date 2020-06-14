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
const int mod = 11092019;
string s;


// compute the number of diferent subsequences
// different in this case means the resulting strings
// are different
ll sol( ){
  int n = size(s);
  vector< ll > dp(n+1);
  vector< int > lst(30,-1);
  dp[0] = 1ll;
  for( int i = 1; i<=n; i++){
    dp[i] = dp[i-1] * 2ll;
    int l = lst[ s[i-1] -'a'] ;
    if( l != -1){
      dp[i] = dp[i]  - dp[ l];
    }
    lst[s[i-1]-'a'] = i-1;
  }
  return dp[n];
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  while( cin >> s){
    ll ans =  1ll;
    map< char, int > cnt;
    // compute the number of diferent subsequences that are
    // different, here if there are repited letters, those 
    // are different, so what makes them different is the index
    // so two subsequences are different if they have at least one
    // index of difference
    for( int i= 0; i< size(s); i++)cnt[s[i]]++;
    for( auto x: cnt) ans = (ans * (x.S+1))%mod;
    cout << ans <<endl;
    /* debug1(sol()); */
  }

  return 0;
}
