#include<bits/stdc++.h>


using namespace std;

typedef long double ld;

const int maxn = 1 << 20;
int dp[maxn];
// find the min distance possible, joining all houses by pairs
// Complexity (2**n)*n*n
int search( int mask ){
  int &ans = dp[mask];
  if( mask != -1) return ans;
  ans = 0;
  int from = -1, to = -1;
  // find a non-selected house
  for( int i = 0; i <= 20 && from == -1; i++)
    if( !(mask & ( 1 << i))){
      from = i;
    }

  for( int j = from + 1; j <=20; j++){
    if( !(mask & (1 <<j))){
      ans = min( search( mask | (1 << from) | (1 << j)), ans);
    }
  }
  return ans;
}

int main(){


  return 0;
}
