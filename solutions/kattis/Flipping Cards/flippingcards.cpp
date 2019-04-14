/**
 *    author:  xdanielsb
 *    created: 2016-12-30       
**/
#include<bits/stdc++.h>

using namespace std;

typedef vector < int > vi;

vi cycles, component;

int find(int x){
  while(component[x] != x){
    x  = component[x];
    component[x] = component[component[x]];
  }
  return x;
}

void unite(int x, int y){
  int xp = find(x), yp = find(y);
  if( xp == yp){
    cycles[xp] += 1;
  }else{
    component[yp]  = xp;
    cycles[xp] += cycles[yp];
  }
}


int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );

  #ifdef LOCAL
    freopen("in.c", "r", stdin);
  #endif

  int numCases, numCards;
  bool flag, aux;
  int x,y;
  cin >> numCases;
  for( int i=0; i< numCases; i++){
    cin >> numCards;
    cycles.resize(2*numCards+1);
    cycles.assign(2*numCards+1, 0);
    component.resize(2*numCards+1);
    for( int j =0; j<= 2*numCards;  j++){
      component[j] = j;
    }

    for( int j = 0; j < numCards; j++){
      cin >> x >> y;
      unite(x,y);
    }
    flag = true;
    for( int c : cycles)
      if( c > 1){
        flag  = false;
        break;
      }
    printf(flag?"possible\n":"impossible\n");
  }


  return 0;
}
