#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
	int row, col;
	cin >> row >> col; 
	vector<vector<int> > G(row, vector<int> (col));
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cin>>G[i][j];
		}
		if(G[i][0]!=1){
			for(int j=0; j<col; j++)
				G[i][j]=1-G[i][j];
		}
	}
	int ans=row<<(col-1);
	for(int j=1; j<col; j++){
		int num=0;
		for(int i=0; i<row; i++){
			if(G[i][j]==1)
				num++;
		}
		ans += (max(num, row-num) << (col-j-1));
	}
	cout << ans << endl;
	return 0;
} 
