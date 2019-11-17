
//	搜索单词  dfs
//  怎样读取字符串 学系 
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 bool judge(vector<string>& board, string words, int x, int y, vector<vector<bool> > &vis, int index){
	    if (index == words.size()) return true;
	    if (x<0||x>=board.size()||y<0||y>=board[0].size()||board[x][y]!=words.at(index)|| vis[x][y])               return false;
	    vis[x][y] = 1;
	    if (judge(board, words, x+1,y,vis,index+1) 
            || judge(board, words, x-1, y, vis, index+1) 
            || judge(board, words, x, y+1, vis, index+1)               
            || judge(board, words, x, y-1, vis, index+1)) 
	    	    return true;
	    vis[x][y] = 0;
	    return false;
    }
    bool search(int m, int n, vector<string>& board, string word){
        vector<vector<bool> > vis(m, vector<bool> (n, 0));
	    for (int i = 0; i < m; i++){
		    for (int j = 0;  j < n; j++)
			    if (judge(board, word, i, j, vis, 0))
				    return true;
	} 
		
	return false;
}
int main(){
	string words;
	string str;
	vector<string> board;
	int i = 0;
	while(cin.get() != '\n' ){
		cin.unget();
		getline(cin, str);
		board.push_back(str); 
		i++;
	} 
	cin >> words;
	words = board[i-1];
	cout << search(board.size(), board[0].size(), board, words) << endl;
	system("PAUSE");
	return 0;
}
