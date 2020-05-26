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
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int num;
    vector< int> odd, even;
    map<int, bool> vis;
    bool ok = false;
    rep(i,0,n) {
      cin >>num;
      if(num%2) odd.PB(num);
      else even.PB(num);
      if( vis.find(num-1) != vis.end() || vis.find(num+1) != vis.end())  ok = true;
      vis[num] = true;
    }
    if( size(even) % 2== 0 || ok){
      cout <<"YES\n";
    }else{
      cout <<"NO\n";
    }



  }

  return 0;
}
