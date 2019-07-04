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

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  int n;
  while( cin >> n){
    string word;cin >>word;
    map< pair<char, int>, int> A;
    map<char, int> cnt;
    rep(i, 0, n){
      cnt[word[i]]++;
      A[make_pair(word[i], cnt[word[i]])] = i+1;
    }
    int q;
    cin >> q;
    while( q--){
      cin >>word;
      int mx = -1;
      map < char, int> aux;
      rep( i, 0, size(word)){
        aux[word[i]]++;
        mx = max(mx, A[{word[i], aux[word[i]]}]);
      }
      cout << mx << endl;
    }
  }





  return 0;
}
