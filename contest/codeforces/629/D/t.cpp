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

  while(t--){
    int n; cin >> n; vi A(n);// debug1(n);
    bool diff = false; // il y a differents?
    rep(i,0,n){
      cin >>A[i];
      if(i && A[i] != A[i-1]) diff = true;
    }
    if(!diff){
      cout << 1 << endl; 
      rep(i, 0, n) cout << 1 << " "; cout <<endl;
      continue;
    }
    if( n % 2 == 0){
      cout << 2 << endl;
      rep(i,0,n) cout << (i%2==0?1:2) << " "; cout << endl;
      continue;
    }
    //search if there is a repeated connected element
    int pos = -1;
    rep(i,0,n){
      if(A[(i+1)%n] == A[i]){ pos = (i+1)%n; break;}
    }
    if(pos!=-1){
      cout << 2 << endl;
      int val = 0;
      rep(i, 0, n){
        if( i != pos) val = val ^ 1 ;
        cout << val+1 << " ";
      }cout <<endl;
    }else{
      cout << 3 << endl;
      rep(i, 0, n-1) cout << (i%2==0?1:2) << " ";
      cout << 3 <<endl;
    }
  }
  return 0;
}
