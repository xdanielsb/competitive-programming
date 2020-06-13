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
  int t, n;
  cin >> t;
  while(t--){
    int x;
    int lst = 0;
    cin  >> n;
    deque< int > ans;
    for( int i = 0; i < n; i++){
      cin >>x;
      if( size(ans) == 0){
        ans.push_back(x);
      }else{
        if( x == ans.back() ) continue;
        int t = ans.back(); ans.pop_back();
        if( !ans.empty()){
          int diff = abs(x - t) + abs(t-ans.back());
          if( diff > abs(x-ans.back())){
            ans.push_back(t);
          }
        }else{
          ans.push_back(t);
        }
        ans.push_back(x);
      }
    }
    cout << size(ans) << endl;

    while(!ans.empty()){
      cout << ans.front() << " ";
      ans.pop_front();
    }
    cout <<endl;

  }

  return 0;
}
