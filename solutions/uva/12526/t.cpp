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
  int nsons=0;
  node *son[26];
  bool isend=false;
  node(){
    rep(i,0 , 26){
      son[i] = nullptr;
    }
  }
};

void insert( node *r, string &s, int i){
  if( size(s) == i) {
    r->isend=true;
    return;
  }
  int x = s[i] - 'a';
  if( r->son[ x ] == nullptr){
    r->son[ x ] = new node();
    r->nsons++;
  }
  insert( r->son[x], s, i+1);
}

int query( node *r, string &s, int i){
  if( size( s ) == i) {
    /* debug2((r==nullptr), r->nsons); */
    return 0;
  }
  int ans = 0;
  int x = s[ i] - 'a';
  if( r->nsons > 1 && i || (r->isend && (i+1)<=size(s))){
    ans = 1 + query( r->son[x], s, i+1);
  }else{
    ans = query( r->son[x], s, i+1);
  }
  return ans;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int n;
  string word;
  while( cin >> n){
    vector< string > A(n);
    node * trie= new node();
    rep(i, 0, n){
      cin >> word;
      A[i] = word;
      insert( trie, word, 0);
    }
    int ans = 0;
    sort( all(A));
    rep( i, 0, n){
      int aux = 0;
      if( size( A[i] ) ==1 ) aux++;
      else aux += 1+query( trie, A[i], 0);
      ans += aux;
    }
    cout << setprecision(2) << fixed;
    /* debug1( ans ); */
    cout << double(ans)/n <<endl;
  }
  
  return 0;
}
