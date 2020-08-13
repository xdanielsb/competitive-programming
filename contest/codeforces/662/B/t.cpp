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
const int maxn = 1e5 + 10;
int cnt[maxn];

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  memset(cnt, 0, sizeof(cnt));
  int n, x, q;
  char opt;
  cin >> n;
  int g2 = 0; // >=2 && <=3
  int g4 = 0; // >= 4
  int g5 = 0; // >= 4 repeated
  int g6 = 0; // 2 repeated 
  for( int i = 0; i < n; i++){
    cin >> x;
    cnt[x]++;
    if(cnt[x] == 2) g2++;
    else if(cnt[x] == 4){
      g4++;
      g2--;
    }else if( cnt[x] > 4 && cnt[x]%4 == 0){
      g5++;
      g6--;
    }else if( cnt[x] > 4 && cnt[x]%4 == 2){
      g6++;
    }
  }

  cin >> q;
  for( int i = 0; i < q; i++){
    cin >> opt >> x;
    if( opt == '-'){
      if(cnt[x] == 2) g2--;
      else if(cnt[x] == 4){
        g4--;
        g2++;
      }else if( cnt[x] > 4 && cnt[x]%4 == 0){
        g5--;
        g6++;
      }else if( cnt[x] > 4 && cnt[x]%4 == 2){
        g6--;
      }
      cnt[x]--;
    }else{
      cnt[x]++;
      if(cnt[x] == 2) g2++;
      else if(cnt[x] == 4){
        g4++;
        g2--;
      }else if( cnt[x] > 4 && cnt[x]%4 == 0){
        g5++;
        g6--;
      }else if( cnt[x] > 4 && cnt[x]%4 == 2){
        g6++;
      }
    }
    /* cout <<endl; d1(i);d3(g2, g4, g5);d1(g6); */
    // now check if is possible 
    if( g4 >= 1){
      if( g2 >= 2 || (g2 == 1 && g4 >=2) || (g4>=2 && g5 >=1) || (g2>=1 && g6 >=1) || (g4>=2) || (g5>=1)){
        cout <<"YES\n";
      }else{
        cout <<"NO\n";
      }
    }else{
      cout << "NO\n";
    }
  }

 
  return 0;
}
