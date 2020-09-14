#include<bits/stdc++.h>
using namespace std;

int getRandom0to3(){
  return rand() % 4;
}

/*
 0  1  2  3
 4  5  6  7 (0, 1, 2, 3 )+ (4, 4, 4, 4) * col 
 8  9  10 11
 12 13 14 15
 * */

int getRandom0to15(){
  int randomCol = getRandom0to3();
  int randomRow = getRandom0to3();
  // this is like a shif in binary 2 pos left
  // 1111 -> 11 11
  return randomRow*4 + randomCol;
}

int main(){
  for( int i = 0; i < 10 ; i++) 
    cout << getRandom0to15() << endl;
}
