#include<bits/stdc++.h>
using namespace std;


vector<int> searchRange(vector<int>& nums, int target) {
  int n = (int)nums.size();
  int l = 0, r = n -1;
  while( l <= r){
    int mid = (l+r)/2;
    if( nums[mid] < target){
      l = mid+1;
    }else if(nums[mid] > target){
      r = mid-1;
    }else{
      int l1=mid, r1=mid;
      while(l1>0 && nums[l1-1] == target) l1--;
      while(r1< n-1 && nums[r1+1] == target) r1++;
      if( nums[r1] != target) r1--;
      return {l1, r1};
    }
  }
  return {-1, -1};
}

int main(){
  vector< int> test = {0,1, 1 , 1, 2 ,3};
  for( int i=  0; i <=3 ; i++){
    for( int a: searchRange(test, i )){
        cout << a << " " ;
    }
    cout <<endl;
  } 

}
