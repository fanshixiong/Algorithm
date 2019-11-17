#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int num[9][9]={6, 6, 6, 6, 6, 6, 6, 6, 6,
6, 7, 7, 7, 7, 7, 7, 7, 6,
6, 7, 8, 8, 8, 8, 8, 7, 6,
6, 7, 8, 9, 9, 9, 8, 7, 6,
6, 7, 8, 9, 10, 9, 8, 7, 6,
6, 7, 8, 9, 9, 9, 8, 7, 6,
6, 7, 8, 8, 8, 8, 8, 7, 6,
6, 7, 7, 7, 7, 7, 7, 7, 6,
6, 6, 6, 6, 6, 6, 6, 6, 6,
};
struct node{
	int line;
	int nun;
}; 
bool cmp(node &a, node &b){
	return a.nun < b.nun;
}
class Solution {
	long best;
	vector<vector<int> > board;
	vector<vector<int> > hash_col;                      //第i列的第j个元素的个数 
	vector<vector<int> > hash_row;                     //第i行的第j个元素的个数 
	vector<vector<int> > hash_ku;                     //第i块的第j个元素的个数
	vector<node> ln;
public:
	Solution(){
		best=0;
		board.resize(9); 
		hash_col.resize(9);
        hash_row.resize(9);
        hash_ku.resize(10);
        ln.resize(9); 
        for(int i = 0; i < 9; i++){
            hash_col[i].resize(10);
            hash_row[i].resize(10);
            hash_ku[i].resize(10);
        }
	}
	bool is_legal(int i, int j, int m){
		int n = i/3*3+j/3;
		if (hash_row[i][m] || hash_col[j][m] || hash_ku[n][m])
			return false;
		return true;
	}

	void place(int i, int j, int m){
		int n = i/3*3+j/3;
		hash_col[j][m]++; hash_row[i][m]++; hash_ku[n][m]++;
		board[i][j] = m;
	}
	void replace(int i, int j, int m){
		int n = i/3*3+j/3;
		hash_col[j][m]--; hash_row[i][m]--; hash_ku[n][m]--;
		board[i][j] = 0;
	}
	void judge(int s, int i, int j){
		if (s == 9) {
			long ans = solve();
			best = max(best, ans);
			return;
		}
		if (j == 9) {	
			judge(s+1, ln[s+1].line, 0);
			return;
		}
		if (board[i][j] == 0){
			for (int k = 1; k <= 9; k++){
				if (is_legal(i, j, k)){
					place(i, j, k);
					judge(s, i, j+1);
					replace(i, j, k);
				}
			}
		}		
		else{
	        judge(s, i, j+1);
	        return;
	    }
	}
    void solveSudoku() {
		for (int i = 0; i < 9; i++){
			board[i].resize(9);
			int k=0;
			for (int j = 0; j < 9; j++){
				cin >> board[i][j];
				if (board[i][j] != 0){
					place(i, j, board[i][j]);
					++k;
				}
			ln[i].line=i; ln[i].nun=k;
			}  
		}
		sort(ln.begin(), ln.end(), cmp);	
        judge(0, ln[0].line, 0);
        if(best)
	        cout << best << endl;
	    else
	    	cout << -1 << endl;
    }
    int solve(){
    	long res = 0;
    	for (int i = 0; i < 9; i++){
    		for (int j = 0; j < 9; j++){
    			res = res + (board[i][j]) * num[i][j];
			}
		}
		return res;
	}
	void print(){
		for (int i = 0; i < 9; i++){
    		for (int j = 0; j < 9; j++){
    			cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}
};
int main(){
	Solution test;
	test.solveSudoku();
	return 0;
} 
