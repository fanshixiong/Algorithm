#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
vector<vector<int> > hash_col(9,vector<int> (10));                      //第i列的第j个元素的个数 
vector<vector<int> > hash_row(9,vector<int> (10));                      //第i行的第j个元素的个数 
vector<vector<int> > hash_ku(10,vector<int> (10));                       //第i块的第j个元素的个数

bool is_legal(vector<vector<char> > &board, int i, int j, int m){
	int n = (i < 3 ? 0 : (i > 5 ? 2 : 1))*3+(j/3+1);
	//int n = i/3*3+j/3;
	if (hash_row[i][m]-1 >0|| hash_col[j][m]-1>0 || hash_ku[n][m]-1>0)
		return false;
	return true;
}
void place(vector<vector<char> > &board, int i, int j, int m){
	int n = (i < 3 ? 0 : (i > 5 ? 2 : 1))*3+(j/3+1);
	//int n = i/3*3+j/3;                  //求块数
	hash_col[j][m]++; hash_row[i][m]++; hash_ku[n][m]++;
	char c = m+'0';
	board[i][j] = c;
}
void replace(vector<vector<char> > &board, int i, int j, int m){
	int n = (i < 3 ? 0 : (i > 5 ? 2 : 1))*3+(j/3+1);
	//int n = i/3*3+j/3;
	hash_col[j][m]--; hash_row[i][m]--; hash_ku[n][m]--;
	board[i][j] = '0';
}
bool judge(vector<vector<char> > &board, int i, int j){
	if (i == 9) 
		return true;
	if (j >= 9) 
		return judge(board, i+1, 0);
	if (board[i][j] == '0'){
		for (int k = 1; k <= 9; k++){
			place(board, i, j, k);
			if (is_legal(board, i, j, k))
				if (judge(board, i, j+1))
					return true;
			replace(board, i, j, k);
		}
	}
	else
		return judge(board, i, j+1);
	return false;
}
void solveSudoku(vector<vector<char> >& board) {
	judge(board, 0, 0);
}
int main(){
	vector<vector<char> > board(9, vector<char> (9));
	freopen("in.txt","r", stdin);
	for (int i = 0; i < 9; i++){
		string ss; getline(cin, ss);
		int k = 0;
		for (int j = 0; j < ss.size(); j++){
			if (ss[j] != ' '){
				board[i][k] = ss[j];
				if (ss[j] != '0')
					place(board, i, k, ss[j]-'0');
				k++;
			}
		}
	}   
	solveSudoku(board);
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++)
			cout << board[i][j]<< " ";
		cout << endl;
	}
	system("pause");
	return 0;
}       
