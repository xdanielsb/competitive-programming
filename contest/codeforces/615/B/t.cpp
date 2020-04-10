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
#ifdef LOCAL
  if(!freopen("in", "r" , stdin)) 
    cerr << "no file..."<<endl;
#endif
  
  int t;
  cin >> t;
  while(t--){int n;
    cin >> n;n++;
    vector < ii > A(n); rep(i, 1, n) cin >>A[i].F >> A[i].S;
    A[0].S = A[0].F = 0;
    sort(all(A));
    bool ok= true;
    rep(i,1 ,n){
      if(A[i].S < A[i-1].S){
        ok = false; break;
      }
    }
    printf(ok?"YES\n":"NO\n");
    if(ok){
      rep(i, 1, n){
        int mr = A[i].F - A[i-1].F;
        int mu = A[i].S - A[i-1].S;
        rep(i,0,mr) cout<<"R";
        rep(i,0,mu) cout<<"U";
      }
      cout <<endl;
    }
  }
  return 0;
}
