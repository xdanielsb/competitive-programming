#include <iostream>
#include <regex>
#include <string>
#include <vector>
#define debug(x) cout <<#x << " = " << x <<endl;

using namespace std;
/**
 * O(N*K), cuadratic, good enough if K and N are less than 101
 * if a machine runs 1e8 operations per second, the solution will last 
 * less than a second
 **/

vector<int> solution(vector<int> N, int K) 
{
  vector<int> ans;
  int bestIndex = 0, greater =-1; bool flag = true;
  for( int i = 0; i < K && flag; i++){
    greater = N[i];
    for( int j = 0; j < N.size() - (K-1) ; j++){
      if( N[i+j] > greater){
        flag = false;
        greater = N[i+j]; 
        bestIndex = j;
      }
    }
  }
  for( int i= 0; i < K; i++){
    ans.push_back( N[i+bestIndex] );
  }
  return ans; 
}
vector<int> toIntVector(string str)
{
  std::vector<int> out;
  std::string i;
  std::istringstream tokenStream(str);
  while (std::getline(tokenStream, i, ','))
  {
    out.push_back(atoi(i.c_str()));
  }
  return out;
}

string fromIntVector(vector<int> arr)
{
  string out = "";
  for (int i=0; i<arr.size(); i++) {
    out += to_string(arr[i]);
    if (i != arr.size() - 1) {
      out += ",";
    }
  }
  return out;
}

int main()
{
  // Read from stdin, solve the problem, write answer to stdout.
  string arrS;
  int K;
  cin >> arrS >> K;
  vector<int> N = toIntVector(arrS);
  cout << fromIntVector(solution(N, K));
}
