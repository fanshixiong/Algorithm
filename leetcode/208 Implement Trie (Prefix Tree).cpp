#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
class TrieNode{
public:
	vector<TrieNode*> child;
	bool isWord;
	TrieNode(): isWord(false), child(26, NULL){
	}
	~TrieNode(){
		for(int i=0; i<child.size(); i++)
			delete child[i];
	}
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p=root;
        for(int i=0; i<word.size(); i++){
        	int x=word[i]-'a';
        	if(p->child[x]==NULL)
        		p->child[x]=new TrieNode();
        	p=p->child[x];
		}
		p->isWord=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p=root;
        for(int i=0; i<word.size(); i++){
        	int x=word[i]-'a';
        	if(p->child[x]==NULL)
        		return false;
        	p=p->child[x];
		}
		return p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p=root;
        for(int i=0; i<prefix.size(); i++){
        	int x=prefix[i]-'a';
        	if(p->child[x]==NULL)
        		return false;
        	p=p->child[x];
		}
		return true;
    }
    private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
 int main(){
 	
 	return 0;
 }
