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
typedef pair<ll,ll> ii;
typedef vector<int> vi;

const int MAXN = (int)1e3 + 17;
int t[MAXN], l[MAXN], r[MAXN];
int sum[MAXN];
bool ok[MAXN];

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int n, m;
  while( cin >> n>> m){
    memset( sum, 0, sizeof sum );
    rept(i, 1, m){
      cin >> t[i] >> l[i] >> r[i];
      if( t[i]){
        sum[l[i]]++;
        sum[r[i]]--;
      }
    }
    rept(i, 1, n){
      sum[i] += sum[i-1];
  //    debug1( sum[i]);
      ok[i] = sum[i] > 0;
    }
    bool isPossible =true;
    rept( i, 1, m){
      if( t[i] == 0){
        bool flag = true;
        rep(j, l[i], r[i]){
          if( ok[j] == 0 ) {
            flag = false;
            break;
          }
        }
        if( flag ){
            isPossible = false;
            break;
        }
      }
    }
    if( isPossible ){
      cout << "YES" <<endl;
      int init = 1e4;
      cout << init << " ";
      rept(i,2, n){
          if( ok[i-1]) init++;
          else init--;
          cout << init << " ";
      }
      cout <<endl;
    }else{
      cout << "NO" <<endl;
    }


  }

  return 0;
}
