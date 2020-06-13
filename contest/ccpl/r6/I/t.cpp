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

int toNum(string a){
  stringstream toNum(a);
  int num;
  toNum >> num;
  return num;
}
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int t;
  string a, b;
  while(cin >> t){
    vector< pair<int, string>> vans;
    for( int i =0; i< t; i++){
      cin >> a >> b;
      if( isdigit(a[0])){
        vans.PB({toNum(a)/2, b});
      }else{
        vans.PB({toNum(b), a});
      }
    }
    sort(all(vans));
    for( int i =0; i<t; i++){
      cout << vans[i].S <<endl;
    }

  }


  return 0;
}
