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



int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

int n; string x;ll v;
while( cin >> n){
  ll i = 0;
  bool ok = true;
  rep( y, 0, n){
    cin >> v  >> x;
    if(x[0] == 'N') i-= v;
    else if( x[0]=='S')i+= v;
    else if(i==0 || i==20000) ok= false;
    if( i <0 || i >20000) ok =false;
  }
  if(i==0 && ok)cout << "YES";
  else cout <<"NO";
  cout <<endl;
}


  return 0;
}
