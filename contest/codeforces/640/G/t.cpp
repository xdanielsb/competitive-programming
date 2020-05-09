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

const int maxn= 1000 +5;
int arr[maxn];

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int t; cin >> t;
  while(t--){
    int n;
    cin >>n;
    if( n<4){
      cout << -1 <<endl;
      continue;
    }
    deque< int > d;
    d.push_front(3);
    d.push_front(1);
    d.push_front(4);
    d.push_front(2);
    rep(i, 5, n+1){
      if (i % 2==0) d.push_front( i);
      else d.push_back(i );
    }
    while(!d.empty()){
      cout << d.front() << " ";
      d.pop_front();
    }
    cout <<endl;
  }

  return 0;
}
