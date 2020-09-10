#include<bits/stdc++.h>
using namespace std;

/*
 Given a reference to a node that belongs to a linked list, 
 remove it from the linked list. Assume that each node has the following structure
*/ 

struct node{
  int val;
  node * next;
  node( int _v){
    val = _v;
    next = nullptr;
  }
};

void removeTargetFromList( node *target){
  if( target->next == nullptr){
    cerr << "It is not possible to remove the element\n";
  }else{
    target->val = target->next->val;
    target->next = target->next->next;
  }
}


void print( node *n){
  if( n == nullptr){
    cout <<endl;
    return;
  }
  cout << n->val << " ";
  print(n->next);
}


int main(){

  node * root = new node( 1 );
  node * a = new node(2);
  node * b = new node(3);
  node * c = new node(4);
  root->next = a;
  a->next = b;
  b->next = c;
  print(root);
  removeTargetFromList(root);
  print(root);

  return 0;
}
