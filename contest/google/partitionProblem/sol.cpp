#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;
const int MAXS = (int)1e5+5;
const int MAXN = (int)1e3+5;
int dp[MAXN][MAXS] ;


int findMin(const vector<int> &A, int n, int S1, int S2){
 if( n == -1) return abs(S1-S2);
 int &aux = dp[n][S1];
 if( ~aux) return aux;
 return aux = min(findMin( A, n-1, S1+A[n], S2), findMin(A, n-1, S1, S2+A[n]));
}

int solution(vector<int> A)
{
  memset( dp, -1, sizeof( dp));
  int ans = findMin( A, A.size()-1, 0, 0);
  // Put your solution here
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

int main()
{
  // Read in from stdin, solve the problem, and write answer to stdout.
  string AS;
  cin >> AS;
  cout << solution(toIntVector(AS));
}
