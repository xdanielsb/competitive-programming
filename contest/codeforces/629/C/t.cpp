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
  int t; cin >>t;
  while( t--){
    string a, b;
    ll n; char x;
    cin >>n;
    bool flag = false;
    rep(i, 0,n ){
      cin >> x;
      if( x == '0'){
        a.PB('0');
        b.PB('0');
      }else if( x =='1'){
        if( !flag){
          a.PB('0');
          b.PB('1');
        }else{
          a.PB('1');
          b.PB('0');
        }
        flag = true;
      }else{ // 2
        if( flag){
          a.PB('2'); 
          b.PB('0');
        }else{
          a.PB('1');
          b.PB('1');
        }
      }
    }
    cout << b <<endl;
    cout << a << endl;
  }
  return 0;
}
