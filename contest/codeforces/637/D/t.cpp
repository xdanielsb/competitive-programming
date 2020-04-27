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

string nums[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int n, k;
const int maxn =2005;
string s[maxn];
int cost[maxn][12];
int dp[maxn][maxn];
string ans ="";
bool find( int i, int k){
  if( i == n )return k == 0;
  int &isPossible = dp[i][k];
  if(~isPossible) return isPossible;
  isPossible = 0;
  for( int j = 9; j>=0; j--){
    if( cost[i][j] != -1  && k >= cost[i][j]){
      isPossible = find(i+1, k-cost[i][j]);
      if( isPossible ){
        ans.PB(j+'0');
        break;
      }
    }
  }
  return isPossible;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  if(!freopen("in", "r" , stdin))
    cerr << "no file..."<<endl;
#endif
  while( cin >> n >> k){
    ans.clear();
    memset(cost,0, sizeof(cost));
    memset(dp, -1, sizeof(dp));
    rep(i,0,n) cin >> s[i];
    rep(i,0,n){
      rep(j,0,10){
        rep(k,0,7){
          char x = s[i][k];
          char y = nums[j][k];
          if( x == '1' && y == '0'){ // it is impossible to gro from i to j
            cost[i][j] = -1;
            break;
          }else if( x =='0' && y == '1'){
            cost[i][j]++;
          }
          // 0,0 there is no cost
          // 1,1 there is no cost
        }
      }
    }
    bool isPossible = find( 0, k);
    if( isPossible){
      for(int i = n-1; i>=0; i--) cout << ans[i];
      cout <<endl;
    }
    else cout << -1 <<endl;
  }
  return 0;
}
