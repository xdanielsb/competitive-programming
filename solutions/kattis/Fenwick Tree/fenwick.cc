/**
 *    author:  xdanielsb
 *    created: 2018-09-29 
**/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector < ll> vll;
struct fw {
  int n; vll data;
  fw(int _n) : n(_n), data(vll(_n)) { }
  void update(int at, ll by) {
   while(at < n) {
    data[at] += by;
    at |= at + 1;
   }
  }
  void update_range( int l, int r, ll by){
    update(l, by); 
    update(r+1, -by);
  }
  ll query(int at) {
   ll res = 0LL;
   while(at >= 0) {
     res += data[at];
     at = (at & (at + 1)) - 1;
   }
   return res;
  }
};

int main(){
#ifdef LOCAL
  freopen("in","r", stdin);
#endif
  ios::sync_with_stdio(0);cin.tie(0);
  int n, q ,a, b;
  char op;
  cin >> n >> q;
  fw *fen  = new fw(n+1);
  for( int i = 0; i < q ; i++){
    cin >> op;
    if( '+' == op){
      cin >> a >> b;
      fen->update(a,b);
    }else{
      cin >>a; a--;
      cout <<  fen->query(a) << endl;
    }
  }
  
}
