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
typedef vector<vi> vvi;

/*
 * Learnings
 * suffix array can produce repeated lcp, then it is necessary to check thate
 */

struct entry { ii nr; int p; };
bool operator <(const entry &a, const entry &b) {
  return a.nr < b.nr;
}

// code from suffix taken from
// Bjarki Ágúst Guðmundsson SuprDewd
struct suffix_array {
  string s;
  int n;
  vvi P;
  vector<entry> L;
  vi idx;
  suffix_array(string _s) : s(_s), n(size(s)) {
    L = vector<entry>(n), P.push_back(vi(n)), idx = vi(n);
    rep(i,0,n) P[0][i] = s[i];
    for (int stp = 1, cnt = 1; cnt >> 1 < n; stp++, cnt <<= 1){
      P.push_back(vi(n));
      rep(i,0,n)
        L[L[i].p = i].nr = ii(P[stp - 1][i],
            i + cnt < n ? P[stp - 1][i + cnt] : -1);
      sort(L.begin(), L.end());
      rep(i,0,n)
        P[stp][L[i].p] = i > 0 &&
        L[i].nr == L[i - 1].nr ? P[stp][L[i - 1].p] : i;
    }
    rep(i,0,n) idx[P[(int)size(P) - 1][i]] = i;
  }
  int lcp(int x, int y) {
    int res = 0;
    if (x == y) return n - x;
    for (int k = (int)size(P)-1; k >= 0 && x<n && y<n; k--)
      if (P[k][x] == P[k][y])
        x += 1 << k, y += 1 << k, res += 1 << k;
    return res;
  }
};

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  string a, b;
  int ca = 0;
  while(cin >> a >> b){
    if( ca ) cout <<endl;
    ca++;
    string t  = a + "#" + b;
    int n = size(t);
    int mn = size(a);
    suffix_array sa(t);
    int blcp = 0; // greatest lcp

    for( int i = 1; i < n ; i++){
      int ia = sa.idx[i], ib = sa.idx[i-1];
      int aux = sa.lcp(ia, ib);
      if( ia < mn && ib < mn ) continue;
      if( ia > mn && ib > mn ) continue;
      if( aux > blcp ){
        blcp = aux;
      }
    }
    if( blcp == 0){
      cout << "No common sequence.\n";
      continue;
    }

    set< string > ans;
    for( int i= 1; i<n; i++){
      int ia = sa.idx[i], ib = sa.idx[i-1];
      if( ia < mn && ib < mn ) continue;
      if( ia > mn && ib > mn ) continue;
      string str = "";
      if( sa.lcp(ia, ib) == blcp ){
        for( int j = ia; j < ia+blcp; j++)
          str.push_back(t[j]);
        ans.insert(str);
      }
    }
    for( string x: ans)
      cout << x <<endl;
  }
  
  
  return 0;
}
