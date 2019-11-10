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
const int MAXN = 2e5+10;
const int oo = INT_MAX;
int memo[MAXN];
int gr[MAXN];
int find( vector< ii > &A, int i ){
	if( i == n) return 0;
	if( ~memo[i] ) return memo[i];
	int ans = oo;
	rep( j, 2, 5){
		int to = min(i + j, n-1);
		int aux = find( A, to+1);
		if( to - i >= 2  && aux != oo)
			if( A[to].F- A[i].F + aux <= ans ){
				ans = A[to].F- A[i].F + aux;
				gr[i] = to-i;
			}
	}
	return memo[i]=ans;
}

int main(){
  //ios::sync_with_stdio( false );
  //cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif


  while( cin >> n){
		memset( memo, -1, sizeof( memo));
		memset( gr, 0, sizeof( gr));
    vector< ii > A(n);
    rep(i ,0 ,n ){
      cin >> A[i].F; A[i].S = i;
    }
    sort(all(A));
    int ans = find(A, 0);

		int lst = 0, ngroups = 0;

		vi res( n );
		int id = 1;
		while( lst < n){
			rep( j, lst, lst+gr[lst]+1) res[A[j].S] = id;
			lst = lst + gr[lst] +1;
			id++;
			ngroups++;
		}
		cout << ans << " " << ngroups << endl;
		rep(i, 0, n) cout << res[i] << " "; cout <<endl;

  }


  return 0;
}
