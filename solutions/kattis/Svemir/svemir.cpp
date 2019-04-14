/**
 *    author:  xdanielsb
 *    created: 2018-07-08   
**/
#include<bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x << " = " << x <<endl;
#define F first
#define S second
using namespace std;


typedef pair < int , int > pi;
typedef pair < int, pi > pii;


int g= 0;
struct p { //planet
  int x,y,z, id;
  p(){} 
  p( int _x, int _y, int _z){
    x = _x;
    y = _y;
    z = _z;
  }
};


bool comp1( const p& a, const p &b){
  return a.x < b.x;
}
bool comp2( const p& a,const  p &b){
  return a.y < b.y;
}
bool comp3( const p& a, const p &b){
  return a.z < b.z;
}
bool comp5( const pii& a, const pii &b){
  return a.F < b.F;
}

vector < p > planet;
vector < int > arr; 
vector < pii > G;
typedef vector < int > vi;

inline int getMin( p &a, p &b){
  int ans =  min( abs(a.x - b.x), min( abs(a.y - b.y), abs(a.z  - b.z)));
  return ans;
}

struct union_find {
    vi data, pe;
    union_find(int n) : data(vi(n)), pe(vi(n, 1)) {
        for(int i=0; i<n; i++) data[i] = i;
    }
    int find(int x) {
        if(data[x] == x) return x;
        data[x] = find(data[x]);
        return data[x];
    }
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return false;
        if(pe[px] > pe[py]) swap(px, py);
        pe[px] += pe[py];
        data[py] = px;
        return true;
    }
};

int main(){
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  int numPlanets;
  cin >> numPlanets; 
  planet.resize(numPlanets);
  arr.resize(numPlanets);
  for( p &a: planet ){
    cin >> a.x >> a.y >> a.z;
    a.id = g++;
  }

  //Create connections tree 
  /*for ( int i = 0; i < numPlanets -1 ; i++){ //consume a lot memory
    for( int j = i+1 ; j< numPlanets; j++){
        G.push_back( pii( getMin( planet[i], planet[j] ), pi( i, j))); 
    }
  }*/
  sort ( planet.begin(), planet.end(), comp1);
  for( int j = 0 ; j< numPlanets -1 ; j++)
    G.push_back( pii( getMin( planet[j], planet[j+1] ),  pi(planet[j].id, planet[j+1].id))); 
  
  sort ( planet.begin(), planet.end(), comp2);
  for( int j = 0 ; j< numPlanets -1 ; j++)
    G.push_back( pii( getMin( planet[j], planet[j+1] ),  pi(planet[j].id, planet[j+1].id))); 
  

  sort ( planet.begin(), planet.end(), comp3);
  for( int j = 0 ; j< numPlanets -1 ; j++)
    G.push_back( pii( getMin( planet[j], planet[j+1] ),  pi(planet[j].id, planet[j+1].id))); 
  

   int sol = 0; 

   sort( G.begin(), G.end(), comp5);
  union_find u(numPlanets);
  for( pii &a: G){
    int from = a.S.F;
    int to = a.S.S;
    if(u.unite(from,to)){
        sol += a.F;
    }
  }
  //display solution
  cout << sol <<endl;

  return 0;
}
