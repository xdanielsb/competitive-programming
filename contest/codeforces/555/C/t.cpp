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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;


const int MAXN = 2e5+17;
int arr [MAXN];
char ans[MAXN];


int find( int l, int r, int lst){
  if( l<=r) return -1;
  if( arr[l] == arr[r]) return find(l+1, r-1, arr[l]);
  if( arr[l] < arr[r] && arr[l] > lst) return 1;
  if( arr[l] <= lst )return 1;
  return -1;
}
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  int n;
  while( cin >> n){
    rep( i,0, n){
      cin >>arr[i];
    }
    int l =0, r = n-1, last = INT_MIN;
    int cnt = 0;
    while( l<=r){
      int mi = min( arr[l], arr[r]);
      if( arr[l] == arr[r] && l<r && arr[l]> last){
          if( l+1<=r && r-1 >=l ){
            int opt = find(l+1, r-1, arr[l]);
            if( opt == 1){
              last = arr[l];
              ans[cnt] = 'R';
              r--;
            }else{
              last = arr[l];
              l++;
              ans[cnt] = 'L';
            }
          }else{
            ans[cnt] = 'L';
            l++;
          }
      }
      else if( mi > last ){
        last = mi;
        if( mi == arr[l]){
          ans[cnt] = 'L';
          l++;
        }else{
          ans[cnt] = 'R';
          r--;
        }
      }
      else if(arr[l] > last){
        last = arr[l];
        l++;
        ans[cnt] = 'L';
      }
      else if(arr[r] > last){
        last = arr[r];
        r--;
        ans[cnt] = 'R';
      }else{
        break;
      }
      cnt++;
    }
    cout << cnt <<endl;
    rep(i, 0, cnt){
      cout << ans[i];
    }
    cout <<endl;
  }




  return 0;
}
