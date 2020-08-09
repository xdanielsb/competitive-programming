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

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
   int t;
   cin >> t;
   while(t--){
     int n;
     cin >> n;
     vector < ll > A(n), B(n);
     ll mna = 1e9, mnb= 1e9;
     for( int i = 0; i < n; i++){
       cin >> A[i];
       mna = min(mna, A[i]);
     }
     for( int i = 0; i < n; i++){
       cin >> B[i];
       mnb = min(mnb, B[i]);
     }
     ll ans = 0;
     for( int i = 0; i < n; i++){
       ll a = A[i], b = B[i];
       ll mn = min(b-mnb,a-mna);
       ans += mn;
       a-= mn; b-= mn;
       ans += b-mnb + a - mna;
     }
     cout << ans <<endl;
   }
  return 0;
}
