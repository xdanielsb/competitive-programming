#include<bits/stdc++.h>

using namespace std;
// this code find the largest path of consecutive numbers increasing
//
//
int n, m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dp[50][50];

int helper(  vector< vector<int >> &ma , int i, int j, int lst){
  if( i < 0 || j < 0 || i >= n || j >=m ) return 0;
  if( lst - ma[i][j] != -1) return 0;
  if( dp[i][j] != -1) return dp[i][j];
  int ans = 0;
  for( int k = 0; k < 4; k++)
    ans = max(ans, helper(ma, i+dx[k], j+dy[k], ma[i][j]));
  return dp[i][j]= 1 + ans;
}

int getLargestPath( vector< vector<int >> &ma ){
  n =(int) ma.size();
  m =(int) ma[0].size();
  int best = 1;
  for( int i = 0; i< n; i++){
    for( int j = 0; j <m; j++){
      int y = helper(ma, i, j, ma[i][j] - 1);
      best = max( best,y );
    }
  }
  return best;
};



int main(){
  memset(dp, -1, sizeof( dp));
  vector< vector< int> > m;
  m.push_back({2, 3, 4, 1});
  m.push_back({1, 2, 4, 5});
  m.push_back({0, 1, 2, 6});

  int ans = getLargestPath( m );
  cout << ans << endl;

  for( int i = 0; i < 5; i++){
    for( int j= 0; j < 5; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
