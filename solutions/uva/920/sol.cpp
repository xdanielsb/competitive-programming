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
typedef long double ld;
typedef pair<ld,ld> ii;
typedef vector<int> vi;

struct point{
  ld x, y;
  point(){}
  point(ld _x, ld _y){
    x = _x;
    y =_y;
  }
};


bool customSort( point &a, point& b){
  return a.x > b.x;
}

ld dist( point &a, point &b){
  return sqrt((a.x-b.x)*(a.x-b.x)+ (a.y-b.y)*(a.y-b.y));
}


point inter( point a, point b, point c, point d){
  ld a1 = b.y - a.y;
  ld b1 = a.x - b.x;
  ld c1 = a1*(a.x) + b1*(a.y);

  ld a2 = d.y - c.y;
  ld b2 = c.x - d.x;
  ld c2 = a2*(c.x) + b2*(c.y);

  ld determinant = a1*b2 - a2*b1;

  //check if determinant if zero, to validate that lines are not
  //parallel

  ld x = (b2*c1 - b1*c2)/determinant;
  ld y = (a1*c2 - a2*c1)/determinant;
  return point(x,y);
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in.c", "r" , stdin);
#endif
  int t, n;
  cin >> t;
  while( t--){
    cin >> n;
    vector< point > A(n);
    rep( i, 0, n ) cin >> A[i].x >> A[i].y;
    sort(A.begin(), A.end(), customSort);

    ld ans  = 0.0;
    if( A[1].y > A[0].y) ans+= dist(A[0], A[1]);
    ld lastx = A[1].x, greaty = max(A[1].y,A[0].y);

    rep( i, 2, n){
      if( greaty <= A[i].y){
        point inte = inter(A[i], A[i-1],point(0.0, greaty), point(300000.0, greaty));
        ans += dist( inte, A[i]);
        greaty = max(greaty, A[i].y);
      }
    }
    cout << setprecision(2) << fixed<<  ans <<endl;
  }
  return 0;
}
