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
int n; 
const int maxn = 2e5 + 10;
int arr[maxn];

// @param st: the end pos of the prefix removed
bool check(int st){
  int l = st, r = n-1;
  int lst = -1;
  while( l <= r){
    if( arr[l] <= arr[r]){
      if( arr[l] < lst ) return false;
      lst = arr[l];
      l++;
    }else{
      if( arr[r] < lst) return false;
      lst = arr[r];
      r--;
    }
  }
  return true;
}

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
    cin >> n;
    for( int i = 0; i < n; i++)
      cin >> arr[i];
      
    int l = 0, r = n-1;
    int ans = 0;
    while( l <= r ){
      int mid = (l + r ) / 2;
      if( check(mid)){
        r = mid-1;
        ans = mid;
      }else{
        l = mid+1;
      }
    }
    cout << ans <<endl;
  }
  return 0;
}
