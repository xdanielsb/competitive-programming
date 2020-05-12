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

const int maxn = 2e5 + 10;
int arr[ maxn ];

int find( int i){
  if(  i == arr[i]) return i;
  return arr[i] = find( arr[i]);
}
void join(int a, int b){
  int xa = find(a), xb = find(b);
  arr[xb] = xa;
}
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  int t; cin >>t;
  while(t--){
    int n, k;
    string s;
    cin >> n >> k  >> s;
    rep(i,0 , n) arr[i] = i % k;
    rep(i, 0, n/2) join( i, n-i-1);
    int ans = 0;
    map< int, vi > cnt;
    rep(i, 0, n){
      cnt[find(arr[i])].PB(s[i]);
    }
    for( pair< int, vi > x: cnt){
      map< int, int> freq;
      int best = 0;
      for( int i: x.S){
        freq[i]++;
        if( freq[i] > best){
          best=freq[i];
        }
      }
      ans+= (size(x.S)-best);
    }
    cout << ans <<endl;
  }

  return 0;
}
