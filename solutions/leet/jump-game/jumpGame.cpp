#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
  int n = (int)nums.size();
  vector<bool> vis(n, false);
  vis[0] = true;
  for( int i = 0; i < n && vis[i]; i++){
    for( int j = i + nums[i]; j >= i && !vis[j]; j--){
      vis[j] = true;
    }
  }
  return vis[n-1];
}

int main(){
  vector<int> nums = {2,3,1,1,4};
  bool ans = canJump(nums);
  cout << ans << endl;
}
