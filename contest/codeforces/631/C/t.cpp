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
  int n, m;
  while(cin >> n>> m){
    bool ok = true;
    vi A(n);//A[i] size of the interval i
    ll sum =0;
    rep(i, 0, m){
      cin >> A[i];
      sum += A[i];
      if(A[i]+i > n) ok = false;
      // this check if there is overlapping checkf e.g n =5, m=3, mi=[3 2 5] you see that the last one overlaps everything
    }
    if( ok  == false || sum < n ){
      cout << -1 <<endl;
      continue;
    }
    // compute the suffix
    vector<ll> s(m+ 1, 0ll);
    for( int i =m-1; i>=0; i--)
      s[i] = s[1+i] + A[i];

    rep(i, 0, m){
      cout << max((ll)i+1, (n-s[i]+1))<< " ";
    }
    cout <<endl;





  }

  return 0;
}
