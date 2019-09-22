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


bool isCover( int x1, int y1, int x2 , int y2, int a1, int b1, int a2, int b2){
   if( x1 <= a1 && y1 <= b1 && x2 >= a2 && y2 >= b2) return true;
   return false;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif


  int x1[3], y1[3], x2[3], y2[3];
  rep(i, 0, 3){
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    //debug2( x1[i], y1[i]);debug2( x2[i], y2[i]);
  }

  bool ok = false;

  rep( i, 1 , 3){
      if( isCover( x1[i],y1[i], x2[i], y2[i], x1[0],y1[0], x2[0], y2[0])){
        ok = true;
      }
  }
  if( !ok ){
    if( x1[1] <= x1[0] && y1[1] <= y1[0] && x2[1] >= x2[0] ){
      if( isCover( x1[2],y1[2], x2[2], y2[2], x1[0], max(y1[0], y2[1]), x2[0], y2[0])){
        ok = true;
      }
    }
    if( x1[1] <= x1[0] && y1[1] <= y1[0] && y2[1] >= y2[0] ){ // higher
      if( isCover( x1[2],y1[2], x2[2], y2[2], max(x1[0], x2[1]), y1[0], x2[0], y2[0])){
        ok = true;
      }
    }

    if( x1[2] <= x1[0] && y1[2] <= y1[0] && x2[2] >= x2[0] ){
      if( isCover( x1[1],y1[1], x2[1], y2[1], x1[0], max(y1[0], y2[2]), x2[0], y2[0])){
        ok = true;
      }
    }
    if( x1[2] <= x1[0] && y1[2] <= y1[0] && y2[2] >= y2[0] ){
      if( isCover( x1[1],y1[1], x2[1], y2[1], max(x1[0], x2[2]), y1[0], x2[0], y2[0])){
        ok = true;
      }
    }

  }
  printf(!ok?"YES\n":"NO\n");


  return 0;
}
