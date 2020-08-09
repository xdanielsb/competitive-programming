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
 int  t;
 cin >> t;
 while(t--){
   int n; cin >> n;
   vector< char > s(n);
   vector< char> lst(n+1, 'x');
   vector< int > idx(n);
   int ans =1, aux =1;
   for( int i = 0; i < n; i++){
     cin >> s[i];
     if( i > 0){
       if( s[i] == s[i-1]){
         while(aux < n && lst[aux] ==s[i])aux++;
       }else{
         aux = 1;
       }
       ans = max(aux, ans);
     }
     idx[i] = aux;
     lst[aux] = s[i];
   }
   cout << ans <<endl;
   for( int i = 0; i < n; i++)
     cout << idx[i] << " ";
   cout <<endl;
 }
 return 0;
}
