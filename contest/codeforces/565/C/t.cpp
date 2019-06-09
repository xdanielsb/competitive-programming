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

int arr[6] = {4, 8,15,16,23,42};

int main(){
 ios::sync_with_stdio( false );
 cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

ll n;
map<int, int> id;
rep( i, 0, 6){
  id[arr[i]] = i;
}
while( cin >>n){
  int x;
  map< int, int > cnt;
  rep(i, 0, n){
    cin >> x;
    if( id[x] ){
      if( cnt[id[x]-1]>cnt[id[x]]) cnt[id[x]]++;
    }else{
      cnt[id[x]]++;
    }
  }
  int ans = n - cnt[id[42]]*6;
  cout << ans <<endl;
}
}
