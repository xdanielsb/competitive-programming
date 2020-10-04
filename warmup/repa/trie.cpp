#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *son[27]= {};
    bool is_end;
    node(){
        this->is_end = false;
    }
};

void insert(node *target, const string &word, int i){
    int n = (int) word.size();
    if(n == i) {
        target->is_end = true;
        return;
    };
    int id = (int)(word[i] - 'a');
    if( !target->son[id]){
        target->son[id] = new node();
    }
    insert(target->son[id], word, i+1);
}

bool contains(node * target, string word, int i){
    int n = (int)word.size();
    if(n == i) return target->is_end;
    int id = (int)(word[i]-'a');
    if( !target->son[id]) return false;
    return contains(target->son[id], word, i+1);
}

bool wordBreak(string s, vector<string>& wordDict) {
    node *root = new node();
    for( string &word: wordDict)
        insert(root, word, 0);
    
    int n = (int)s.size();
    vector<bool> dp(n+1, false);
    dp[0] = true;
    for( int len = 1; len <= (int)s.size(); len++){
        for( int i = 0; i < len; i++){
            if( dp[i] &&  contains(root, s.substr(i, len-i), 0)){
                /* cout << i << " " << len  <<  " " << s.substr(i, len-i) << " " <<endl; */
                dp[len] = true;
            }
        }
    }
    return dp[n];
}

int main(){
  vector<string> words;
  words.push_back("cats");
  words.push_back("dog");
  words.push_back("sand");
  words.push_back("and");
  words.push_back("cat");
  node *root =new node();
  for( string &word: words)
    insert(root , word, 0);

  string w = "catsandog";

 bool ans =  wordBreak(w, words); 
 cout << ans <<endl;

  return 0;
}
