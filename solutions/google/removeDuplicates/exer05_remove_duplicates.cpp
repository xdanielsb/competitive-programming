#include<bits/stdc++.h>
using namespace std;
/*
 * return the number of different elements in a vector of numbers
 */
int removeDuplicates(vector< int > &nums){
  int n = nums.size();
  if( n == 0) return 0;
  int numDiff = 1; // number of different elements
  for( int i = 1;  i < n; i++){
    if( nums[i] != nums[i-1] ){
      nums[numDiff] = nums[i];
      numDiff++;
    }
  }
  return numDiff;
}

int main(){
  vector< int > v = {-1,-1, 2,0, 1, 0, 0, 2 ,3 , 4};
  sort( v.begin(), v.end());
  int numDiff = removeDuplicates( v );
  for( int i = 0; i  < numDiff; i++)
    cout << v[i] <<  " ";
  cout << endl;

}
