#include<iostream>
#define debug( x ) cout << #x << " = " << x <<endl;
#include<vector>
#include<string>
using namespace std;
typedef vector < string > vs;

struct node{
  node* next[26];
  bool isEnd;
  node(){
    isEnd = false;
    for( int i= 0; i < 26; i++) next[ i ] = nullptr;
  }
};

void insert( const string word, node * root,unsigned int i=0){
  if( i == word.size() ){
    root->isEnd = true;
    return;
  }
  int idx = word[i] - 'a';
  if( !root->next[ idx ] ){
    root->next[idx] = new node();
  }
  insert( word, root->next[idx], i+1);
}

void match( node * root,const string &p, unsigned int i =0, string acum = ""){
  if( i < p.size()){
    int idx = p[ i ]  - 'a';
    if( !root->next[ idx ]) return;
    match( root->next[idx], p, i+1);
  }else{
    if( root->isEnd) cout << p << acum << endl;
    for( int j= 0; j< 26; ++j){
      string aux = acum;
      aux.push_back( ('a'+j));
      if( root->next[ j ] ) match( root->next[ j ] , p, i+1, aux);
    }
  }
}

void getWordsMatched( const vs words, const string p){
  node* root = new node();
  for( const string &word: words) {
    insert( word, root);
  }
  match( root, p);
  delete root;
}

int main(){
  vs words = {"a", "ab", "ba", "aba", "bbb"};
  string pr = "ab";
  getWordsMatched( words, pr);
  return 0;
}
