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
  freopen("in", "r" , stdin);
#endif
  int q;
  cin >> q;
  ll n, k;
  while( q--){
    cin >> n >> k;
    vector<char > vs(n);rep(i,0 ,n) cin >> vs[i];

    ll i= 0;
    for( ; i <n ; i++){
      if( vs[i] =='0') cout << '0';
      else break;
    }
    ll ones = 0;
    
    for(; i < n ; i++){
      if( vs[i] == '1'){
        ones++;
      }
      else if( vs[i] == '0'){
        if( ones < k){
          cout << '0';
          k -= ones;
        }else{
          ll aux = ones;
          rep(j, 0, aux - k){
            cout << '1'; ones--;
          }
          cout << '0';
          rep(j, 0, ones) cout << '1';
          ones = 0;
          i++;
          while( i < n) {
            cout << vs[i] ; i++;
          }
        }
      }
    }

    while( ones > 0) {
      cout << '1'; ones--;
    }
    cout <<endl;
  }
  return 0;
}
