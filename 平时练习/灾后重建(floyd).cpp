#include<iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
	int N, M;
	cin >> N >> M;
	vector<vector<int> > dist(N, vector<int>(N, 0x3f3f3f3f));
	vector<int> time(300);
	for (int i = 0; i < N; i++)
		cin >> time[i];
	for (int i = 0; i < N; i++)
		dist[i][i] = 0; 
	for (int i = 0; i < M; i++){
		int x, y, d;
		cin >> x >> y >>d;
		dist[x][y] = dist[y][x] = d;
	}
	int Q;
	cin >> Q;
	int k = 0;
	for (int i = 0; i < Q; i++){
		int x, y, t;
		cin >> x >> y >> t;
		while (time[k] <= t && k < N){
			for (int i = 0; i < N; i++){
				for (int j = 0; j < N; j++){
					dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
				}
			}
			k++;
		}
		if (dist[x][y] == 0x3f3f3f3f || time[x] > t || time[y] > t){
			cout << -1 << endl;
		}
		else
			cout << dist[x][y] << endl;
	}
}
