#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Tram{
	int N;
	int beg, end;
	vector<vector<int> > G; 
	vector<vector<int> > dist;
public:
	Tram(){
		cin >> N >> beg >> end;
		G.resize(N+1);
		dist.resize(N+1);
		for (int i = 1; i<=N; i++){
			int x; cin >> x;
			G[i].resize(N+1);
			dist[i].resize(N+1); 
			for(int j = 1; j<=N; j++)
				dist[i][j]=0x3f3f3f3f; 
			for (int j=0; j<x; j++){
				int y; cin >> y;
				if(y!=i){
					G[i][y]=1;
					if(j!=0)                  //看题目：默认为第一条 ,有限制时 长度为零 
						dist[i][y]=1;
					else
						dist[i][y]=0;
				}
			}
		}
	}
	void Floyd(){
		for (int k=1; k<=N; k++){
			for (int i=1; i<=N; i++){
				for (int j=1; j<=N; j++){
					if (dist[i][k]+dist[k][j] < dist[i][j])
						dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
		if(dist[beg][end]!=0x3f3f3f3f)
			cout<<dist[beg][end]<<endl;
		else 
			cout << -1 << endl;
	}
};
int main(){
	Tram test;
	test.Floyd();
	return 0;
} 
