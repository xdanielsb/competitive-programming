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

int gcd( int a, int b){
  if( b == 0 ) return a;
  return gcd(b, a%b);
}

ll lcm(int a , int b){
  return a * 1ll* b / gcd(a, b);
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin)) 
    cerr << "no file..."<<endl;
#endif
  int t;
  cin >>t ;
  while(t--){
    int n;
    cin >> n;
    int a = n-1, b = 1;
    ll mn = lcm(a, b);
    for( int i = 2; i*i <= n; i++){
      if(n % i == 0){
        int a1 = i, b1 = n - i;
        if( lcm(a1, b1) < mn){
          mn = lcm(a1, b1);
          a= a1;
          b= b1;
        }
        int a2 = n/i, b2 = n - n/i;
        if( lcm(a2, b2) < mn){
          mn = lcm(a2, b2);
          a= a2;
          b= b2;
        }
      }
    }
    cout << a << " " << b<<endl;
  }
  
  return 0;
}
