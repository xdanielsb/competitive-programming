/**
 *    author:  xdanielsb
 *    created: 2018-07-13
**/
#include<bits/stdc++.h>
#define debug(x) cout << #x  << " = " << x <<endl
using namespace std;

int getHash( string line) {
  int hash = 0;
  for( char c : line){
    hash ^= int(c);
  }
  return hash;
}


int main(){
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
  int numFiles;
  string line;
  while ( cin >> numFiles && numFiles) {
    getline(cin ,line);
    vector < string >  vs( numFiles);
    vector < int > hash( numFiles);
    int r = 0;
    for( string &s: vs) {
      getline (cin , s);
      hash[r] = getHash( s );
      r++;
    }

    int unique = numFiles, coll =0;
    for ( int i = 0; i < numFiles; i++){
      bool isUnique = true;
      for ( int j = i+1; j < numFiles; j++){
          if ( vs[i] == vs[j] ) isUnique = false;
          else
            if( hash[i] == hash[j] ) coll++;
      }
      if( !isUnique) unique--;
    }
    cout << unique << " " << coll <<endl;

  }
  return 0;
}
