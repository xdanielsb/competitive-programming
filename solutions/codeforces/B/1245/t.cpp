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
  int q,n;cin >> q;
  string s ;
  string aux = "RPS";
  while( q--){
    vi many( 3, 0), cnt(3, 0);
    cin >> n;
    rep(i , 0 , 3 ) cin >> many[i];
    cin >> s;
    rep(i, 0, n) cnt[aux.find( s[i] )]++;
    
    int how = min( many[0], cnt[2]) + min( many[1], cnt[0]) + min( many[2], cnt[1]);
    string ans(n, 'x');
    if( how*2 >= n){
      cout <<"YES" <<endl;
      rep(i, 0, n){
        if( s[i] == 'R' && many[1]) many[1]--, ans[i]='P';
        else if( s[i] == 'P' && many[2]) many[2]--, ans[i]='S';
        else if( s[i] == 'S' && many[0]) many[0]--, ans[i]='R';
      }
      rep(i, 0, n){
        if( ans[i] =='x') rep(j, 0, 3) if( ans[i] == 'x' && many[j] ) ans[i] = aux[j], many[j]--;
      }
      rep(i, 0, n) cout << ans[i];
      cout <<endl;
    }else{
      cout <<"NO" <<endl;
    }
  }
  return 0;
}
