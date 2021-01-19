#include <bits/stdc++.h>
#define endl '\n'
#define d(x) cout <<#x << " = " << x << ", ";
#define d1( x ) d(x); cout <<endl;
#define d2( x, y ) d(x); d(y); cout <<endl;
#define d3( x, y, z ) d(x); d(y); d(z); cout <<endl;
#define F first
#define S second
#define PB push_back
#define endl '\n'
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int p = 89;
const ll m = 1e9+9;

string random_str(const int &len) {
  string tmp_s;
  static const char alphanum[] =
    "abcdefghijklmnopqrstuvwxyz";
  srand( (unsigned) time(NULL) * rand());
  tmp_s.reserve(len);
  for (int i = 0; i < len; ++i)
    tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
  return tmp_s;
}

ll compute_hash( const string s ){
  const int n = (int) s.size();
  ll hash = 0, pow = 1;
  for( int i = 0; i < n; i++){
    hash =  (hash + (s[i]-'a' + 1)*1ll*pow + m) % m;
    pow = (pow * p) % m;
  }
  return hash;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  /* freopen("in", "r" , stdin); */
#endif
  int num = 100000;
  int tgt = 5; // target
  int coll  = 0;
  map<int, string> mem;
  for( int i = 0; i < num; i++){
    string rnds = random_str(tgt);
    int hash = compute_hash(rnds);
    if( mem.find(hash) != mem.end() && mem[hash] != rnds){
      coll++;
      cout << "String " << mem[hash] << " collides with " << rnds <<endl;
      d2(mem[hash], compute_hash(mem[hash]));
      d2(rnds, compute_hash(rnds));
    }
    mem[hash] = rnds;
  }
  cout << "Total collisions: " << coll << " / " << (num-coll) <<endl;
  return 0;
}
