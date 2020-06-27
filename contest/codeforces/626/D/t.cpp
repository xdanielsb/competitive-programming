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


/* idea 
 *
 * build the k-bit of the solution 
 * question: how can we know that the k-bit is on
 *  first 
 *    - for each k-bit take all numbers module pow(2,k+1), this is because what is left will not contribute
 *      that the k-bit is on
 *  second:
 *    - T = pow(2, k)
 *    - there are two conditions to check that k-bit is on
 *    - one: T <= ai + bi < 2T
 *        ejm: 2 bit (4)
 *        8   4   2   1
 *        0   1   0   0 -> 4 
 *        0   1   0   1 -> 5
 *        0   1   1   0 -> 6
 *        0   1   1   1 -> 7   
 *        all this values are between 4 y 7, and the 2 bit is alwais one
 *    - two: 3T <= ai + bi < 4T
 *      after this we can check that all values are betwen 12(1100) y 15(1111)
 *      and the 2-bit is always one :)
 */ 
int n;
const int maxn =4e5+10;
int arr[maxn];
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin)) 
    cerr << "no file..."<<endl;
#endif

   while(cin >> n){
      for( int i = 0; i < n; i++){
        cin >> arr[i];
      }

      int ans = 0; 
      for( int bit = 26; bit >= 0; bit--){
        int T = 1 << bit;
        for( int i = 0; i < n; i++){
          arr[i] %= 2*T;
        }
        sort(arr, arr+n);
        int cnt = 0;
        /* cout <<endl; */
        /* debug2(bit, T); */
        int lb, ub;
        int l, r;
        for( int i = 0; i< n; i++){
          int cur = arr[i];
          lb = lower_bound(arr+i+1, arr+n,T-cur) - arr;
          ub = lower_bound(arr+i+1, arr+n,2*T-cur) - arr;
          
          cnt += ub - lb ;

          lb = lower_bound(arr+i+1, arr+n,3*T-cur) - arr;
          ub = lower_bound(arr+i+1,arr+n, 4*T-cur) -arr;

          cnt += ub - lb ;
          
        }
        if(cnt&1){
          /* debug2(bit, cnt); */
          ans += T;
        }
      }
      cout << ans <<endl;

   }
  return 0;
}
