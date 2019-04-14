
/**
 *    author:  xdanielsb
 *    created: 2016-12-28 
**/
#include <iostream>
#include <string>
#include <map>

using namespace std;
/*
 * Daniel Santos
 * Ten Kinds of people
 * Kattis
 */


static int rows =1001;
static int cols =1001;
static int seed = 7;
static char maze[1001][1001];
static int sol[1001][1001];
static int posr_out , posc_out;
static char pas,sal;
static map<char,string> mymap = {
                { '0', "binary" },
                { '1', "decimal" },
                };

void read(){
    for(int row = 0; row < rows; row ++){
        for (int col = 0; col < cols; col ++){ 
            cin >> maze[row][col];
        }
    }
}


bool solve(int posr,int posc){
    
    if (posr < 0 || posr >= rows || posc < 0 || posc >= cols || sol[posr][posc] == seed || maze[posr][posc] != pas  ){
        return false;
    }
    
    sol[posr][posc] = seed;

    solve(posr+1, posc);
    solve(posr-1, posc);
    solve(posr, posc+1);
    solve(posr, posc-1) ;
    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int in_r , in_c;
    int num_cases ;

    cin >> rows >> cols; 
    read();
    
    cin >> num_cases;
    
    while(num_cases--){
        cin >> in_r>>in_c>> posr_out >> posc_out;

        pas = maze[--in_r][--in_c];
        sal = maze[--posr_out][--posc_out];

        if (pas == sal){
            if ( sol[in_r][in_c] >= 7){
                sol[in_r][in_c] == sol[posr_out][posc_out] ? cout << mymap.find(pas)->second<<endl: cout << "neither"<<endl;
            }else{
                solve( in_r, in_c);   
                sol[posr_out][posc_out] == seed ? cout << mymap.find(pas)->second<<endl: cout << "neither"<<endl;
            }
        }else{
            cout << "neither"<<endl;
        }

        seed ++;
    }
         
  return 0;

}
