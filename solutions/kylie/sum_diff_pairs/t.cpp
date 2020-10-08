// given a list of pairs you want to get sum of the absolute difference of all possible pairs
#include<bits/stdc++.h>
using namespace std;

int findDifferencePairs1( const vector<int> &arr){
  int sum = 0;
  int n = (int)arr.size();
  for( int i = 0; i < n; i++){
    for( int j = i+1; j < n; j++){
      sum += abs( arr[i]-arr[j]);
    }
  }
  return sum;
}

int findDifferencePairs2( vector< int> arr){
  int sum = 0;
  int n = (int) arr.size();
  sort(arr.begin(), arr.end());
  for( int i=1, j = n-1, k =1 ; k <n ; i++, k++, j--)
    sum += abs(arr[k] - arr[k-1]) * i * j;
  return sum;
}

int main(){
  vector< int > arr;
  int maxn = 10;
  cout << "The array is:" <<endl;
  for( int i= 1;i <= maxn; i++){
    arr.push_back( i);
    random_shuffle(arr.begin(), arr.end());
    cout << arr[i-1] << " ";
  }
  cout << endl;
  cout << "The difference utilizing the O(n^2) way is: ";
  int ans1 = findDifferencePairs1( arr);
  cout << ans1 << endl;
  cout << "The difference utilizing the O(nlog(n)) way is: ";
  int ans2 = findDifferencePairs2( arr);
  cout << ans2 <<endl;
  return 0;
}
