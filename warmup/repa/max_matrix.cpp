#include<bits/stdc++.h>
using namespace std;


int dp1[50][50];
int dp2[50][50];

int maxSquare(vector< vector< int> >& ma){
  int n = (int) ma.size();
  int m = (int) ma[0].size();
  int ans = 0;
  for( int i= 0 ; i < n; i++){
    for( int j= 0;  j < m; j++){
      if( ma[i][j] == 1){
        dp1[i][j ] = 1;
        if( i > 0 && j  > 0)
          dp1[i][j]   += min({ dp1[i-1][j],dp1[i][j-1], dp1[i-1][j-1]});
        ans = max( ans, dp1[i][j]);
      }
      cout << dp1[i][j] << " ";

    }
    cout << endl;
  }
  return ans; 
}



int maxRectangle( vector< vector<int>> &ma){
  int nrows = (int) ma.size();
  int ncols = (int ) ma[0].size();
  stack< int > s;
  vector< int > row(ncols, 0);
  int ans = 0;
  for( int i= 0 ; i < nrows; i++){
    for( int j = 0; j < ncols; j++){
      if( ma[i][j] == 0) row[j] = 0;
      else row[j]++;
    }
    stack< int> s;
    for( int j = 0; j <= ncols; j++){
      if( s.empty()) s.push(j);
      else{
        while( !s.empty() &&  row[j] < row[s.top()]){
          ans = max(ans, row[s.top()] * ( j - s.top()));
          s.pop();
        }
        s.push(j);
      }
    }
  }
  return ans;
}


int main(){
  memset(dp1, 0, sizeof(dp1));
  vector<vector<int>> ma;
  ma.push_back({0,1, 1, 1});
  ma.push_back({0,1, 1, 1});
  ma.push_back({0,1, 1, 1});
  ma.push_back({0,1, 1, 1});

 int ans =  maxSquare( ma);
 int ans2 = maxRectangle(ma);
 cout << ans  <<endl;
 cout << ans2 <<endl;
  return 0;
}
