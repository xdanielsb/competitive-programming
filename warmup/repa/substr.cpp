#include<bits/stdc++.h>
using namespace std;
int main(){

  string str = "iamanapple";
  for( int i = 0; i < (int)str.size(); i++){
    cout << str.substr(i, 1) << endl;
  }
  return 0;
}
