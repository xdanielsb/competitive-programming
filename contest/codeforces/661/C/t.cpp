#include <bits/stdc++.h>
#define endl '\n'
#define d(x) cout <<#x << " = " << x << ", ";
#define d1( x ) d(x); cout <<endl;
#define d2( x, y ) d(x); d(y); cout <<endl;
#define d3( x, y, z ) d(x); d(y); d(z); cout <<endl;
#define F first
#define S second
#define PB push_back
#define size( x )   int( ( x ).size( ) )
#define endl '\n'
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int cnt[100];

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int t;
  cin >> t;
  while(t--){
    memset(cnt, 0, sizeof(cnt));
    int n, x;
    cin >> n;
    for( int i = 0; i < n; i++){
      cin >> x;
      cnt[x]++;
    }
    int best = 0;
    for( int i = 2; i <= 100; i++){
      int aux = 0;
      for( int j  = 1; j < i && i-j>=j; j++){
        if( i - j == j ){
          aux += cnt[j] / 2;
        }else{
          aux += min( cnt[j], cnt[i - j]);
        }
      }
      best = max(best, aux);
    }
    cout << best <<endl;
  }
 
  return 0;
}
