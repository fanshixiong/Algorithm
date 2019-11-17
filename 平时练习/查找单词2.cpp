
// ≤È’“µ•¥ 2 
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class TrieNode{
	public:
		const static int MaxBranchNum = 26;
		TrieNode *nextBranch[MaxBranchNum];
		string word;
		TrieNode(){
			for (int i = 0; i < 26; i++)
				nextBranch[i] = NULL;
		}
};
class Trie{
	public:
		TrieNode *root;
		Trie(){
			root = new TrieNode();
		}
		void insert(string words){
			if (words.size() == 0) return;
			TrieNode *node = root;
			for (int i = 0; i < words.size(); i++){
				if (!node->nextBranch[words[i]-'a'])
					node->nextBranch[words[i]-'a'] = new TrieNode();
				node = node->nextBranch[words[i]-'a'];
			}
			
			node->word = words;
		}
};
void judge(vector<string>& board, TrieNode *node, int x, int y, vector<vector<bool> > &vis, vector<string> &res){
		if (!node->word.empty()) {
			res.push_back(node->word);
			node->word.clear(); 
		}
	    vis[x][y] = 1;
		for (int i = 0; i < 4; i++){
			int x1 = x+d[i][0];
			int y1 = y+d[i][1];
			if(x1>=0&&x1<board.size()&&y1>=0&&y1<board[0].size()&&!vis[x1][y1]&&node->nextBranch[board[x1][y1]-'a'])
			    judge(board, node->nextBranch[board[x1][y1]-'a'], x1, y1, vis, res);
		}
	    vis[x][y] = 0;
	    return;
    }
    void search(vector<string>& board, vector<string> &words, vector<string> &res){
        vector<vector<bool> > vis(board.size(), vector<bool> (board[0].size(), 0));
        Trie *T = new Trie();
        for (int i = 0; i < words.size(); i++){
        	T->insert(words[i]);
		}
		for (int i = 0; i < board.size(); i++){
		    for (int j = 0;  j < board[i].size(); j++)
			    if (T->root->nextBranch[board[i][j]-'a'])
			    	judge(board, T->root->nextBranch[board[i][j]-'a'], i, j, vis, res);
				    
	} 
}
int main(){
	freopen("in.txt","r", stdin);
	string str;
	vector<string> board;
	while(cin.get() != '\n' ){
		cin.unget();
		getline(cin, str);
		board.push_back(str);
	} 
	vector<string> words;
	while(cin.get() != '\n' ){
		cin.unget();
		getline(cin, str);
		words.push_back(str);
	} 
	vector<string> res;
	search(board, words, res);
	for (int i = 0; i<res.size(); i++)
		cout << res[i] << endl;
	system("pause");
	return 0;
}
