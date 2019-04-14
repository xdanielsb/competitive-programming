/**
 *    author:  xdanielsb
 *    created: 2019-02-25
**/
#include <bits/stdc++.h>
#define debug1( x ) cout << #x << " = " <<  x << endl;
#define debug2( x, y) cout <<#x << " = " << x << " , " <<#y << " = " << y <<endl;

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;


const int MAXN = 2000001;

 

int main(){
  ios::sync_with_stdio( false );
  cin.tie( 0 );
#ifdef LOCAL
  freopen("in.c", "r" , stdin);
#endif
  
  vector< bool > primes(MAXN, true);
  vector< int > dp(MAXN, 0);
    primes[0] = primes[1] = false;
    for( int i= 2; i*i <=MAXN; i++)
    {
        if( primes[i] ){
            for( int j = i+i ; j <=MAXN; j+=i){
                primes[j] = false;
            }   
        } 
    }   
    
    int q;cin >>q;
  while( q--){
      int x; cin >> x;
      
      if( dp[x] !=0 ){
        cout << dp[x] <<'\n';
        continue;
      }
      if( primes[x] ){
        cout << 1 <<'\n';
        continue;
      }
      int orig= x;
      int  ans =1, count = 0, wow = 0;
      if((x&1) ==0){
        wow++;
        while((x&1) ==0){
          x>>= 1;
          count++;  
        }
        ans *= (count +1);  
       }
       if(primes[x]){
            wow++;
            ans<<=1;    
        }else{
            int s = sqrt(x);
            for(int i  =3; i <= s; i+=2){
                if( x % i ==0){
                    count = 0; wow++;
                    while( x% i == 0){
                        count++;
                        x/= i;  
                    }   
                    ans *= (1+count);
                }
            }
            if( primes[x] ){
                ans *= 2;
                wow++;
            }   
        }
        dp[orig] =  ans - wow;
        cout << dp[orig] <<'\n';
      }
  return 0;
}
