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
string s; int n; int m;

int dp[10000][11];
int  ways( int i, int mod){
  int &ans = dp[i][mod];
  if( i== n) return ans = (mod == 0?1:0);
  if(~ans) return ans;
  ans = 0;
  if( s[i] == 'X'){
    for( int j = 9; j>=0; j--){
      int nmod = (mod*10+j)%m;
      ans += ways( i+1, nmod);
    }
  }else{
    int nmod = (mod*10+(s[i]-'0'))%m;
    ans += ways( i+1, nmod);
  }
  return ans;
}
string str="";
void findk( int i, int mod, int k){
  if( i== n) return;
  int &ans = dp[i][mod];
  if( s[i] == 'X'){
    for( int j = 9; j>=0; j--){
      int nmod = (mod*10+j)%m;
      if(dp[i+1][nmod] >= k){
        str.push_back(j+'0');
        findk(i+1, mod, k);
        break;
      }
      k-= dp[i+1][nmod];
    }
  }else{
    str.push_back(s[i]);
    int nmod = (mod*10+(s[i]-'0'))%m;
    findk( i+1, nmod, k);
  }
}


int main(){
  //ios::sync_with_stdio( false );
  //cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif

  while( cin >> s >> m){
    memset(dp,-1, sizeof(dp));
    n = size(s);
    str = "";
    debug2(s, m);
    int nways = ways( 0, 0);
    rep(i, 0, 10){
      rep(j,0, 10) cout <<dp[i][j]<<" ";
      cout <<endl;
    }
    findk(0,0, 1);
    debug2(nways, str);
  }


  return 0;
}
