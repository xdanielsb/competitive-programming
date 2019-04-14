/**
 *    author:  xdanielsb
 *    created: 2018-10-14 
**/
#include<bits/stdc++.h>
using namespace std; 
int const MAX = 1e8+5;
bitset<MAX> primes; 
void sieve(){
  int to = sqrt( MAX );
  primes[0] = primes[1] = 0;
  for( int i= 2; i <=to; i++){
    if(!primes[i]) continue;
      for( int j =i*i; j < MAX; j+=i)
        primes[j] = 0;
  }
}
int sum( int n){
  int res =0;
  for( int i =2; i <= n; i++)  res+= primes[i];
  return res;
}

int main(){
#ifdef LOCAL 
  freopen("in", "r",stdin);
#endif
  int n, q;
  cin >> n >> q;
  primes.flip();
  sieve();
  cout << sum(n) <<endl;
  while( q--){
    cin >> n; cout << primes[n] <<endl;
  }
  return 0;
}
