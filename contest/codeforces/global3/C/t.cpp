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

const int MAXN = 3e5+5;
int A[MAXN], POS[ MAXN ];
vector< ii > changes;

void change(int i, int j){
  if( i == j) return;
   POS[ A[j] ] = i; POS[ A[i] ] = j;
   swap(A[i], A[j]);
   changes.PB({i, j});
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  int n;
  while( cin >> n){
    changes.clear();
    rep( i, 1, n+1) cin >> A[i];
    rep( i, 1, n+1) POS[ A[i] ] = i;
    rep(i, 1, n+1){
      if (POS[i] == i) continue;
      if( abs(POS[i]-i)*2>=n){
        change( POS[i], i);
      }else if (POS[i] <= n/2){
        change(POS[i], n);
        if( abs(n-i)*2 >=n){
          change(n,i);
        }else{
          i--;
        }
      }else{
        change(POS[i], 1);
        if( abs(1-i)*2 >=n){
          change(1,i);
        }else{
          i--;
        }
      }
    }
    cout << size(changes) <<endl;
    rep( i, 0, size(changes)){
      cout << changes[i].F << " " << changes[i].S <<endl;
    }
  }
  return 0;
}
