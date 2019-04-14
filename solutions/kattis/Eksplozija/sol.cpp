/**
 *    author:  xdanielsb
 *    created: 2018-07-16       
**/
#include<bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl;
#define pb push_back
#define f first
#define c second
using namespace std;

typedef pair < int , int > ii;
typedef vector < ii > vii;

char S[1000005];
char P[50];
int  d[1000005];
int LS, PS;
int DD = 1;

inline void solve(){
  stack < ii > st;
  for ( int i = 0; i < LS; i++){
    if( S[i] == P[0] ){
      st.push( ii( i, 1) );
      continue;
    }
    while( !st.empty() ){
      ii aux = st.top(); st.pop();
      if( P[aux.c] != S[i] ){
        st = stack<ii>(); //empty the stack instead of while
        break;
      }
      aux.c += 1;
      if( aux.c == PS ) d[aux.f] = d[i] = DD++; // mark ini and end to delete
      else st.push( aux );
      break;
    }
  }
  bool f = true;
  for( int i = 0; i < LS; i++){
    int val = d[i];
    if( d[i] ){ // not print that section
      i++;
      while( d[i] != val) i++;
      continue;
    }else{
      f = false;
      cout << S[i];
    }
  }
  if( f ) cout <<  "FRULA";
  cout <<endl;
}


int main(){
  ios::sync_with_stdio( 0 );
  cin.tie( 0 );
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif

  scanf("%s%s",S,P);
  LS = strlen( S );
  PS = strlen( P );
  /* debug(LS); */

  if( PS > LS ){
    cout << S << endl;
    return 0;
  }
  if( PS == 1 ){
    string aux = "";
    bool f = true;
    for( int i = 0; i < LS; i++){
      if (S[i] != P[0]){
        cout <<  S[i];
        f = false;
      }
    }
    if( f ) cout << "FRULA" <<endl;
    return 0;
  }

  solve( );

  return 0;
}
