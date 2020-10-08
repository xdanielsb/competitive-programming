#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  unordered_map< int, int> mem;
  int n = nums.size();
  set< vector<int>> unique_ans;
  for( int i = 0; i < n; i++) mem[nums[i]] = i;
  for( int i = 0; i < n; i++){
    for( int j = i+1; j < n; j++){
      int sum = nums[i] + nums[j];
      if( mem.find(-sum) != mem.end() ){
        int k = mem[-sum];
        if ( i == k || j == k) continue;
        vector< int > aux = {nums[i], nums[j], nums[mem[-sum]]};
        sort(aux.begin(), aux.end());
        unique_ans.insert(aux);
      }
    }
  }
  vector< vector<int>> ans;
  for( vector<int> u: unique_ans) ans.push_back(u);
  return ans;
}

int main(){
  vector< int> v = {-1,0 ,0,0, 1, 2, 3, -3};
  vector< vector< int> > ans = threeSum( v);
  for( vector< int > x: ans){
    for( int y: x) cout << y << " " ;
    cout <<endl;
  }
}
