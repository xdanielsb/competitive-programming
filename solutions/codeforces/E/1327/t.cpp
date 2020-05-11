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
// this recursion does not work, because
// doesn count all blockes ejm.
// idea: is to take in paper block of size n, for example
// n = 3
// X??
// ?X?
// ??X
// and count in this type of block how many there are you will guess a pattern
// the count will be
// n =4 ans ={34200 2610 180 10}
void count( int pos,int lst=0, int cnt=0){

  if(pos == n){
    ans[cnt]++;
    return;
  }
  rep(i, 0, 10){
    if(pos && i == lst){
      count(pos+1, i, cnt+1);
    }else{
      ans[cnt]++;
      count(pos+1, i, 1);
    }
  }
}

ll powm( ll b, ll e){
  ll ans = 1;
  while( e > 0){
    if( e & 1){
      ans = (ans * b) %mod;
      e--;
    }
    b = (b *1ll* b )%mod;
    e = e /2;
  }
  return ans;
}


int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  while(cin >>n){
    ll res;
    rep(i, 1, n){
      res = 18ll * powm(10ll, n-i)%mod;
      res = (res + (n-i-1)*81ll * powm(10ll, n-i-1))%mod;
      cout << res << " ";
    }
    cout <<10 << endl;
  }


  return 0;
}
