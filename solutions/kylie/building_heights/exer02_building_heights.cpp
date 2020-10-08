#include<bits/stdc++.h>
using namespace std;

/*
   On a street, there are N buildings with different heights
   numbered from 0 to N-1 from left to right.
   For each building, you want to know if it is possible to see
   the horizon to the right, that is, if you are at the top of
   building X and you look to the right and there is no higher
   building it means you can see the horizon and you should print -1.
   Otherwise, you want to know the height of the first building
   that obstructs your view
   */

// brute-force approach

// h -> heigths is a vector
// time O(N  ^ 2 );
// memoire O(N)
vector< int > getHeigthsNextHigherBuilding( vector< int> h ){
  int n = h.size();
  vector< int > ans(n);
  for( int i = 0; i < n; i++){
    bool found = false;
    for( int j = i+1; i< n && !found; i++){
      if( h[i] < h[j] ){
        ans[i] = h[j];
        found = false;
      }
    }
    if(!found) ans[i] = -1;
  }
  return ans;
}

// h -> heights
vector< int > getHeightHigherBuilding(const vector< int> & h){
  int n = h.size();
  vector< int > ans(n);
  stack<int> s;
  for( int i = n-1; i>=0; i--){
    while( !s.empty() && s.top() <= h[i]){
      s.pop();
    }
    if(s.empty()){
      ans[i] = -1;
    }else{
      ans[i] = s.top();
    }
    s.push(h[i]);
  }
  return ans;
}

int main(){
  vector< int> h = { 30 , 3 , 4, 1 , 5, 7, 8, 1, 2 , 1, 3, 3};
  vector< int> ans = getHeightHigherBuilding( h);
  for( int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout <<endl;
  return 0;
}
