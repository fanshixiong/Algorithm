#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int N; 
vector<string> grids;
vector<vector<int> > vis;
int dist[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, -1, -1, 1, 1, 1, -1, -1};
string target = "yizhong";
bool flag = 0;
void dfs(int x, int y, int key){
	cout << x << " " << y << " " << grids[x][y] << " " << key-1 << " " << target[key-2] << endl;
	if (key >= 8){
		flag = 1;
		return;
	}
	for (int i = 0; i < 8; i++){
		int x1 = x+dist[i][0];
		int y1 = y+dist[i][1];
		if (x1>=0 && x1<N && y1>=0 && y1<N && grids[x1][y1]==target[key-1]){
			vis[x1][y1] = key;
			dfs(x1, y1, key+1);
			if (flag && grids[x1][y1] != 'i') break;
		}
	}	
}/*
void dfs(int x, int y){
	for (int i = 0; i < 8; i++){
		int j;
		for (j = 1; j <= 6; j++){
			int x1 = x+j*dist[i][0];
			int y1 = y+j*dist[i][1];
			if(x1<0 || x1>=N || y1<0 || y1>=N || grids[x1][y1]!=target[j])
				break;
		}
		if (j == 7){
			for (int k = 0; k <= 6; k++){
				int x1 = x+k*dist[i][0];
				int y1 = y+k*dist[i][1];
				vis[x1][y1] = k+1;
			}
		}
	}
}*/
int main(){
	cin >> N;
	grids.resize(N);
	vis.resize(N);
	for (int i = 0; i < N; i++){
		cin >> grids[i];
		vis[i].resize(N);
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (target.find(grids[i][j], 0) == -1)
				grids[i][j] = '*';
			else if (grids[i][j] == 'y')
				dfs(i, j, 1);
		}
	}
	for (int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if (!vis[i][j])
				cout << '*';
			else
				cout << grids[i][j];
		}
		cout << endl;
	}
	return 0;
} 
