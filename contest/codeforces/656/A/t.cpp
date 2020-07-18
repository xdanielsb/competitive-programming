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

ll x, y, z;
bool check( ll a , ll b, ll c){
  bool ok =  max(a,b)==x && max(a, c) == y && max(b,c) == z;
  if( ok ){
    cout <<"YES\n";
    cout << a << " " << b << " " << c<<endl;
  }
  return ok;
}

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
    cin >> x >> y >> z;

    if( check(x, x , y)){
    }else if( check(x, x, z )){
    }else if( check(x, z, y)){
    }else if( check(x, z, z)){
    }else if( check(y, x, y )){
    }else if( check(y, x, z)){
    }else if( check(y, z, y )){
    }else if( check(y , z, z )){
    }else{
      cout <<"NO" <<endl;
    }
    

  }

  
  return 0;
}
