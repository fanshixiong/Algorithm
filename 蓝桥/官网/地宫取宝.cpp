#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m, k;
vector<vector<int> > maze(51, vector<int>(51));
int dp[51][51][21][21];
int dfs(int x, int y, int cnt, int Max1){
	if(dp[x][y][cnt][Max1+1] != -1) return dp[x][y][cnt][Max1+1]; //Max ³õÊ¼»¯Îª-1 
	int sum = 0;
	if(x == n-1 && y == m-1){
		if(maze[x][y] > Max1){
			if(cnt == k || cnt == k-1)
				sum++;
		}
		else if(cnt == k){
			sum++;
		}
		//dp[x][y][cnt][Max1+1]
		return sum;
	}
	if(x+1<n){ //down
		if(maze[x][y] > Max1){
			sum += dfs(x+1, y, cnt+1, maze[x][y]);
			sum %= 1000000007;
		}
		sum += dfs(x+1, y, cnt, Max1);
		sum %= 1000000007; 
	}
	if(y+1<m){//right
		if(maze[x][y] > Max1){
			sum += dfs(x, y+1, cnt+1, maze[x][y]);
			sum %= 1000000007;
		}
		sum += dfs(x, y+1, cnt, Max1);
		sum %= 1000000007;
	}
	dp[x][y][cnt][Max1+1] = sum;
	//cout << sum << endl;
	return dp[x][y][cnt][Max1+1];
}
int main(){
	cin >> n >> m >> k;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			cin >> maze[i][j];
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0, 0, -1) << endl; //
	return 0;
}
