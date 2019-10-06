#include <iostream>
#include <string>

using namespace std;
/**
 *  minutes -[0...5][0...9] 
 * hours - here is the conditions
 * - if start by [0,1] then is follow by[0...9]
 * - if start by [2] then is follow by[0..3]
 */

string utilTime(const string &T){
  string ans = "";
  if( T[0] == '?'){
    if( T[1] == '?' or (isdigit(T[1]) && (T[1]-'0')<= 3))
			ans = "23";
    else
			ans = "1"+T[1];
  }else{
    ans.push_back(T[0]);
    if( T[0]== '2'  ){
      if( T[1] == '?' ) ans.push_back('3');
      else ans.push_back(T[1]);
		}else{
			if( T[1] == '?' ) ans.push_back('9');
      else ans.push_back(T[1]);
		}
  }
	ans.push_back(':');
  if( T[3] == '?') ans.push_back( '5');
  else ans.push_back( T[3]);
  if( T[4] == '?') ans.push_back( '9');
  else ans.push_back(T[4]);
  return ans;
}


string solution(string T) {
  string ans = utilTime( T );
  return ans;
}

int main() {
  // Read from stdin, solve the problem, write answer to stdout.
  string input;
  cin >> input;
  cout << solution(input);
}

