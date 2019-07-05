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

const int MAXN =(int)3e5 + 17;

ll Tree[MAXN];

int n, q;
void build(){
  for( int i= n-1; i > 0; i--){
    Tree[i] = Tree[i<<1]*1ll*Tree[i<<1|1];
  }
}
void update( int x, int y){
  x+=n;
  Tree[x] =y;
  for( ; x  > 1; x >>=1){
    Tree[x >> 1] = Tree[x] *1ll* Tree[x ^1];
  }
}

ll query( int l, int r){
  ll res =1ll;
  for( l+=n,r+=n; l <r ; l >>=1, r>>=1){
    if( l & 1 ) res = res *1ll*Tree[l++];
    if( r & 1) res = res *1ll*Tree[--r];
  }
  return res;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int l, r; char opt;
  while( cin >> n>> q){
    rep(i, 0, MAXN) Tree[i]= 1ll;
    rep(i, 0, n){
      cin >> Tree[i+n];
      if( Tree[i+n] >0 ) Tree[i+n] = 1;
      if( Tree[i+n] <0 ) Tree[i+n] = -1;
    }
    build(  );
    
    rep(i, 0, q){
      cin >> opt >> l >> r;
      /* cout <<endl<<"\t"; */
      /* rep(i, 0, n) cout << Tree[i+n] << "\t"; */
      /* cout <<endl; */
      if( opt == 'C'){
        if( r > 0 ) r = 1;
        else if( r < 0) r =-1;
        update(l-1, r);
      }else{
        ll ans = query( l-1, r );
        if( ans == 0) cout << 0;
        else if( ans > 0) cout << '+';
        else cout << '-';
      }
    }
    cout <<endl;
    
  }  
  return 0;
}
