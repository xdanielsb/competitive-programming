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


struct node{
  node* son[10];
  bool is_end = false;
  node(){
  }
};

void insert( node *n, string &num, int pos = 0){
  if( pos == size( num)){
    n->is_end = true;
    return;
  }
  int id = num[ pos ] - '0';
  if( !n->son[id] ){
    n->son[id] = new node();
  }
  insert( n->son[id], num, pos+1);
}

bool contain(node *n, string &n1, int pos = 0){
  int id = n1[ pos ] - '0';
  if( n->is_end ) return true;
  if( !n->son[ id ]) return false;
  if( size(n1) -1 == pos ) return n->son[id];
  return contain( n->son[ id ], n1, pos+1);
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  int t; cin >>t;
  string num;
  int n;
  while( t--){
    cin >> n;
    node *trie = new node();
    bool ok =  true;
    rep( i,0 , n){
      cin >> num;
      if( contain( trie, num)) ok = false;
      if( ok )
      insert(trie, num);
    }
    printf(ok?"YES\n":"NO\n");
  }
  
  return 0;
}
