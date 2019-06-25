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
typedef pair< int, ii> iii;
typedef vector<int> vi;

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

int n,m;
while( cin >> n>>m ){
  priority_queue < iii, vector<iii>, greater<iii> > pq;
  rep(i, 1, m+1){
    //cout << 0 << " " << abs((m+1) -2 *i) << " " << i <<endl;
    pq.push({0, {abs((m+1) - 2*i), i}});
  }
  rep(i, 0, n){
    iii y = pq.top(); pq.pop();
    cout << y.S.S <<endl;
    y.F++;
    pq.push(y);
  }
}

  return 0;
}
