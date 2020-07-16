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
    vector< int > A(n);
    for( int i = 0; i < n; i++) cin >> A[i];

    int state =  0;
    int lst = A[0];
    int a=0, b =0, c = 0;
    for( int i = 1; i < n; i++){
      if(state == 0 ){
        if( A[i] <= lst){
          lst = A[i];
          a = i;
        }else if(A[i] > lst){
          b = i;
          lst = A[i];
          state = 1;
        }
      }else if(state==1){
        if( A[i] >= lst){
          lst = A[i];
          b = i;
        }
        else if( A[i] < lst){
          c = i;
          state = 2;
        }
      }
    }
    if( state == 2){
      cout <<"YES\n";
      cout << a+1 << " " << b+1 << " " << c+1 <<endl;
    }else{
      cout <<"NO\n";
    }
  }
  
  
  return 0;
}
