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
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int t; cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    vi A(n); vector< bool > used(n, false);
    rep(i, 0, n) {
      cin >> A[i];
      A[i]--;
    }

    vector<ii> two_node_cycles;
    vector<tuple<int, int, int>> ans;
    rep(i, 0, n){
      if( used[i] == false){
        vi cycle;
        int j = i;
        while( used[j] == false){
          used[j] = true;
          cycle.PB(j);
          j = A[j];
        }
        while( size(cycle) >= 3){
          // x -> y -> z -> x
          int z = cycle.back(); cycle.pop_back();
          int y = cycle.back(); cycle.pop_back();
          int x = cycle.back();
          if( size(cycle) == 1)
            cycle.pop_back();
          ans.PB(tie(x,y,z));
          k = k -1;
        }
        if( size(cycle) == 2){
          two_node_cycles.PB({cycle[0], cycle[1]});
        }
      }
    }
    while( size(two_node_cycles) > 1){
      // a -> b -> a
      // c -> d -> c
      ii f = two_node_cycles.back(); two_node_cycles.pop_back();
      ii s = two_node_cycles.back(); two_node_cycles.pop_back();
      // a -> b -> c
      ans.PB(tie( f.F, f.S, s.F));
      // b -> c -> d
      ans.PB(tie( f.S, s.F, s.S));
      k = k - 2;
    }
    if( size(two_node_cycles)){
      k = -1;
    }
    if( k < 0 ){
      cout << -1 << endl;
    }else{
      cout << size(ans) <<endl;
      rep(i, 0, size(ans)){
        cout << get<0>(ans[i])+1 << " ";
        cout << get<1>(ans[i])+1 << " ";
        cout << get<2>(ans[i])+1 << " ";
        cout <<endl;
      }

    }
  }


  return 0;
}
