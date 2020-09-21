#include<bits/stdc++.h>
using namespace std;

struct node {
  bool is_end;
  node * son[10];
  node(){
    is_end = false;
  }
};

void insert(node *n, const string & w, int i=0 ){
  int ns = (int)w.size();
  if( ns == i){
    n->is_end = true;
    return;
  }
  int id = w[i] - 'a';
  if( !n->son[id]){
    n->son[id] = new node();
  }
  insert( n->son[id], w, i+1);
}

bool contains(node *n, const string &w, int i= 0){
  int ns = (int) w.size();
  if( ns == i){
    return n->is_end;
  }
  int id = w[i] -'a';
  if( !n->son[id]) return false;
  return contains(n->son[id], w, i+1);

}

int main(){
  vector<string> words; 
  words.push_back("hello");
  words.push_back("he");
  words.push_back("hi");
  node *root = new node();
  for( string &w: words)
    insert(root, w);

  words.push_back("h");
  for( string &w: words){
    cout << contains( root, w) << endl;
  } 


  return 0;
}
