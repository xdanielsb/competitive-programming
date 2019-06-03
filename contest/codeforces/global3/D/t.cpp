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


struct tt{
  int a,b,c;
};

bool sortC(tt &x, tt &y){
   return x.b > y.b;
}
bool sortD(tt &x, tt &y){
  return x.a < y.a;
}
int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  int n;
  while( cin >> n){
    vector < ii > A(n);
    vector < tt > C, D;
    rep( i, 0, n){
      cin >> A[i].F >> A[i].S;
      if( A[i].F < A[i].S){
        C.PB( {A[i].F, A[i].S, i+1});
      }else{
        D.PB( {A[i].F, A[i].S, i+1});
      }
    }
    cout<< max(size(C), size(D)) <<endl;;
    if( size(C) > size(D)){
      sort(C.begin(),C.end(), sortC);
      rep( i, 0, size(C)) cout << C[i].c << " ";
    }else{
      sort(D.begin(), D.end(), sortD);
      rep( i, 0, size(D)) cout << D[i].c << " ";
    }
    cout <<endl;
  }

  return 0;
}
