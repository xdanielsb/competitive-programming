#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int _v){
      this->val = _v;
    }
};

bool isPali = true;
ListNode * getOppositeNode( ListNode*n, ListNode *head){
  if( n == nullptr) return head;
  ListNode *opposite = getOppositeNode( n->next, head);
  if( n->val != opposite->val) isPali = false;
  return  opposite->next;
}

bool isPalindrome(ListNode* head) {
  getOppositeNode(head, head);
  return isPali;
}

int main(){
  ListNode *a = new ListNode(1);
  ListNode *b = new ListNode(0);
  ListNode *c = new ListNode(1);
  a->next = b;
  b->next = c;
  cout << isPalindrome( a ) << endl;
  
}
