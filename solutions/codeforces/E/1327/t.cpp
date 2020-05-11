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
int ans[10], n;
ll mod = 998244353;
const int maxn =  2e5 +10;
ll res[maxn];

// this is the recursion
// just for testing
// learned: clean the memo once used
void count( int pos, int num=0, int lst=0, int cnt=1){
  if(pos == n){
    ans[cnt]++;
    return;
  }
  rep(i, 0, 10){
    if(pos && i == lst){
      count(pos+1,num*10+i, i, cnt+1);
    }else{
      if(pos>0)ans[cnt]++;
      if( lst==-1) lst=0;
      count(pos+1, num*10+i, i, 1);
    }
  }
}


int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  while(cin >>n){
    res[0] = 10;
    res[1] = 180;
    rep(i, 2, n+1)
      res[i] = (res[i-1] * 10 ) % mod;

    rep(i, 0, n)
      cout << res[n-i-1] << " "[i==n-1];
    cout <<endl;
  }


  return 0;
}
