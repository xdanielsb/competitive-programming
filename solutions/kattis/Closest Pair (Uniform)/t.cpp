/*
 * author: xdanielsb
 */
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
typedef long double lf;
typedef pair<int, int> ii;
typedef vector<int> vi;



struct point{
  int id;
  lf x[2];
  void show(){
    cout << x[0] << " " << x[1] << " ";
  }
};

struct knode{
  point p;
  int id;
  knode *l, *r;
  int d;
  int val;
  knode(int _d) {
    d = _d;
    l = nullptr;
    r = nullptr;
  }
};

bool cmp1( const point &p1, const point &p2){
  return p1.x[0] < p2.x[0];
}

bool cmp2( const point &p1, const point &p2){
  return p1.x[1] < p2.x[1];
}

knode* build( vector<point> &A,int l, int r, int d){
  knode *root = new knode( d );
  if( l >= r ){
    root->p = A[l];
    return root;
  }
  int mid = (l+r)/2;
  if( d == 0){
    nth_element(A.begin()+l, A.begin()+mid,A.begin()+r+1, cmp1);
  }else{
    nth_element(A.begin()+l, A.begin()+mid,A.begin()+r+1, cmp2);
  }
  root->val = A[mid].x[d];
  root->p = A[mid];
  root->d = d;
  root->l = build( A, l, mid, d^1);
  root->r =  build( A, mid+1, r, d^1);
  return root;
}

inline lf dist( const point &a, const point &b){
  lf ans = 0.0;
  rep(i , 0 ,2){
    lf aux = a.x[i]-b.x[i];
    ans += aux*1ll*aux;
  }
  return ans;
}
void findNearest( point &to, knode *root, lf &ans, point &nans, int d){
  if( root == nullptr) return;
//  root->p.show();
  lf dis = dist( to, root->p);
  if( to.id != root->p.id && dis < ans){
    ans =dis;
    nans = root->p;
  }
  lf delta= to.x[d] - root->val;
  delta = delta * 1ll * delta;
  if( to.x[d] > root->val){
    findNearest( to, root->r, ans, nans, d^1);
    if( ans >= delta )  findNearest( to, root->l, ans, nans, d^1);
  }else{
    findNearest( to, root->l, ans, nans, d^1);
    if( ans >= delta )      findNearest( to, root->r, ans, nans, d^1);
  }
}


int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif


  int n;
  while( cin >> n && n){

    vector< point > pts(n);
    rep( i, 0, n)  {
      cin >> pts[i].x[0] >> pts[i].x[1];
      pts[i].id = i;
    }

    point nans1, nans2, naux;
    knode *root = build( pts , 0, n-1, 0);

    lf ans= LONG_LONG_MAX,aux;
    for( int i= 0; i < n; i++){
      aux= LONG_LONG_MAX;
      findNearest(pts[i], root, aux, naux, 0);
      if(aux < ans){
        ans = aux;
        nans1 = pts[i];
        nans2 = naux;
      }
    }
    cout << setprecision( 5) << fixed;
    nans1.show();
    nans2.show();
    cout <<endl;
  }



  return 0;
}
