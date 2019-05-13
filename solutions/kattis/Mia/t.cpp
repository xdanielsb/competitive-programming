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

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int a, b, c,d ;
  while( cin >> a >> b >> c >> d){
    if( a== 0 && b == 0 && c == 0 && d==0) break;
    if( a > b ) swap( a , b);
    if( c > d ) swap( c, d);
    if( a == 1 && b == 2){
      if( c == 1 && d == 2) cout << "Tie." <<endl;
      else cout << "Player 1 wins."<<endl;
    }else if( c == 1 && d == 2){
      if( a == 1 && b == 2)cout << "Tie." <<endl;
      else cout << "Player 2 wins."<<endl;
    }else if( a == b){
      if( c == d){
          if( a == c )cout <<"Tie."<<endl;
          else if( a > c )cout <<"Player 1 wins."<<endl;
          else  cout <<"Player 2 wins."<<endl;
          
      }else{
          cout <<"Player 1 wins."<<endl;
      }
    }else if(c == d){
      if( b == a){
          if( a == c )cout <<"Tie."<<endl;
          else if( a > c ) cout <<"Player 1 wins."<<endl;
          else  cout <<"Player 2 wins."<<endl;
      }else{
          cout <<"Player 2 wins."<<endl;
      }
    }else if( b > d){
        cout <<"Player 1 wins."<<endl;
    }else if( b < d){
        cout <<"Player 2 wins."<<endl;
    }else{
      if( a == c)cout <<"Tie." <<endl;
      else if( a > c)cout << "Player 1 wins."<<endl;
      else cout <<"Player 2 wins."<<endl;
    }
  }
  return 0;
}
