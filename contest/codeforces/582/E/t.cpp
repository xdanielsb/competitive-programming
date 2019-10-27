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

int n;
bool f( string &s, string &t,  string ans, int j, int a, int b, int c){
  debug2( j, ans);
    if( j == 3*n ){
       bool ok = a == 0 && b == 0 && c == 0;
       if( ok ) cout << "YES" << endl <<ans <<endl;
       return ok;
    }
    if( j > 0 ){
      rep(i , 0, 3){
        string org = ans;
        if( ans.back() == s[0] && ('a'+i) == s[1] ) continue;
        if( ans.back() == t[0] && ('a'+i) == t[1] ) continue;
        if( i == 0 && a <= 0) continue;
        if( i == 1 && b <= 0) continue;
        if( i == 2 && c <= 0) continue;
        org.PB(('a'+i));
        bool res =  f( s, t, org, j+1, a-(i==0), b-(i==0), c-(i==2));
        if( res ) return res;
      }
    }else{ // i ==0
      rep(i , 0, 3){
       string org = ans;
       org.PB(('a'+i));
       bool res =  f( s, t, org,j+1, a-(i==0), b-(i==0), c-(i==2));
       if( res ) return res;
      }
    }
    return false;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
 
  string s,t;
  while( cin >> n){
    cin >> s >> t;
    string ans = "";
    bool ok =   f( s, t, ans,0,n,n,n);
    if( !ok) cout << "NO" <<endl;
  }
  return 0;
}
