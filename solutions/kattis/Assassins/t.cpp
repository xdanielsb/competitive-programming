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
typedef long double ld;
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  int n, m;
  while( cin >> n >> m ){
    int total = 1 << n;
    int from, to;
    // all possible combinations
    vector<ld> probs(total);
    double pkill;
    int all_on = (1<<n)-1;
    probs[all_on] = 1.; // at begining all assassins are alive
    rep(i, 0, m){
      cin >> from >> to >> pkill;
      from--; to--;
      rep(j, 0, total){
        // if both assassins are alive
        if( ( j & (1 << from)) && ( j & ( 1 << to))){
          // all other assassins alive in j except  the one attempted to kill
          // increase their probability to be allive
          probs[ j  & ~(1 << to)] +=   pkill * probs[j];
          //  probability that live
          probs[j] *= ( 1 - pkill);
        }
      }
    }

    vector<double> ans(n);
    rep(i, 0, total){
      /* debug2(i , probs[i]); */
      rep(j, 0, n){
        if( i & (1 << j)) ans[j] += probs[i];
      }
    }

    rep(i, 0, n){
      cout << fixed << setprecision(7) << ans[i] << endl;
    }

  }





  return 0;
}
