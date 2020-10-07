#include<bits/stdc++.h>
using namespace std;

int findPairs(vector<int>& nums, int k) {
  int ans = 0, n = nums.size();
  if(k < 0 ) return 0;
  sort(nums.begin(), nums.end());
  int i = 0, j = 1;
  while( i < n && j < n){
    int diff = abs(nums[j] - nums[i]);
    if( diff == k){
      ans++;
      i++;
      while( i < n  && nums[i] == nums[i-1] ) i++;
      if( j < i) j = i;
    }else if( diff < k ){
      j++;
    }else{
      i++;
    }
    if( i == j) j++;
  }
  return ans;
}

int main(){
  vector<int> v = {1, 1, 1, 2, 2};
  int k = 0;
  int ans = findPairs(v, k);
  cout << ans <<endl;

  return 0;
}
