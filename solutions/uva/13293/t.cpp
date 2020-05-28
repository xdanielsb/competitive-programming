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
typedef vector<string> vs;

vs split(string line, char d){
  vs el;
  stringstream ss(line);
  string item;
  while(getline(ss, item, d)) el.PB(item);
  return el;
}

int getScore( vs &l){
  int ans = 0;
  rep(i, 1, 6){
    rep(j, 0, 4)
      ans += (l[i][j*2+0] == '1');
    ans += (l[i][8] =='1')*2;
  }
  return ans;
}
string toLower(string a){
  rep(i, 0, size(a))
    a[i] = tolower(a[i]);
  return a;
}
bool cmpstr( string &a, string &b){
  return toLower(a) < toLower(b);
}

bool cmp( pair<int, string> &a, pair<int, string> &b){
  if( a.F != b.F) return a.F > b.F;
  return cmpstr(a.S, b.S);
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif

  int n;
  int c = 1;
  while( cin >> n){
    string line,dummy;

    vector< pair< int, string> > ans; // (score, name)
    getline(cin, dummy);
    rep(i, 0, n){
      getline(cin, line);
      vs l = split( line, ';');
      int score = getScore( l );
      ans.PB({score, l[0]});
    }

    sort( ans.begin(), ans.end(), cmp);
    cout << "Case "<< c++ << ":" <<endl;
    for( pair< int, string> x: ans){
      cout << x.S << " " << x.F <<endl;
    }

  }



  return 0;
}
