#include<iostream>
#include <vector>
using namespace std;
int dist[4] = {1, -1, 5, -5};
int graph[12] = {1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 13, 14};
vector<int> Youp(5);
int vis[5] = {0};
void dfs(int x){
	for (int i = 0; i < 4; i++){
		int d = Youp[x] + dist[i];
		if (d <= 0 || d == 5 || d > 14 || d == 10) continue;
		for (int j = 0; j < 5; j++){
			if (!vis[j] && Youp[j] == d){
				vis[j] = 1;
				dfs(j);
			}
		}
	}
} 
int main(){
	int ans = 0;
	for (int i = 0; i <= 12; i++){
		for (int j = i+1; j <= 12; j++){
			for (int x = j+1; x <= 12; x++){
				for (int y = x+1; y <= 12; y++){
					for (int z = y+1; z <= 12; z++){
						Youp[0] = graph[i];Youp[1] = graph[j];Youp[2] = graph[x];Youp[3] = graph[y];Youp[4] = graph[z];
						for (int i = 0; i < 5; i++)
							vis[i] = 0;
						dfs(0);
						bool b = 1;
						for (int i = 0; i < 5; i++)
							if (!vis[i])
								b = 0;
						if (b)
							ans++;
						else
							continue;
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
} 
