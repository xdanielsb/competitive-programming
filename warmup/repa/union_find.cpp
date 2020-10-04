#include<bits/stdc++.h>
using namespace std;

int p[100];
int find(int a ){
  return p[a] == a ? a : find(p[a]);
}
void join( int a, int b){
  int pa=find(a), pb = find(b);
  p[pb] = pa;
}


int main(){
  for( int i = 0; i < 100; i++)
    p[ i ] = i;
  join(0, 1);
  join(0, 2);
  cout << find(0) <<endl;
  cout << find(1) <<endl;
  cout << find(2) << endl;
  cout << find(3) <<endl;
}
