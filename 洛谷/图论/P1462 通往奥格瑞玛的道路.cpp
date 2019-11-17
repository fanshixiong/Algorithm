#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
struct Node{
	int end;
	long long value;
};
class node{
	int N;
	long long T;                     //��ĸ���    Ѫ�� 
	vector<long long> cost;             //ÿ������շ� 
	vector<long long> dist;             //���� 
	vector<vector<Node> > G;       //ͼ 
	long long L, R; 
public:
	node(){
		L=R=0; 
		int M;
		cin >> N >> M >> T;
		cost.resize(N+1);
		dist.resize(N+1); 
		for (int i = 1; i<=N; i++){
			cin >> cost[i];
			R = max(R, cost[i]);                   //1
			dist[i]=0x3f3f3f3f;
		}
		L = max(cost[1], cost[N]);                 //2 ����Сϸ�� ʡʱ�� 
		G.resize(N+1);
		for(int j=1; j<=M; j++){
			long long x, y, z;
			cin >> x >> y >> z;
			if(x==y) continue;                    //����ȥ���Ի� 
			Node tp; tp.end = y; tp.value=z;
			G[x].push_back(tp);
			tp.end=x; 
			G[y].push_back(tp);  
		} 
	}
	bool SPFA(long long x){
		vector<bool> vis(N+1);
		for (int i=1; i<=N; i++)                        ///
			dist[i]=0x3f3f3f3f;                         //   ��һ���ǳ���Ҫ 
		queue<int> q;
		vis[1]=1; dist[1]=0; q.push(1);
		while(!q.empty()){
			int tmp = q.front();
			q.pop();
			vis[tmp]=0;
			for (int i = 0; i < G[tmp].size(); i++){
				int t = G[tmp][i].end;
				if (dist[t] > dist[tmp] + G[tmp][i].value){
					dist[t]=dist[tmp]+G[tmp][i].value;
					if (!vis[t] && cost[t] <= x){
				//	if(relax(i, tmp) && !vis[t] && cost[t]<=x){
						vis[t]=1;
						q.push(t);
					}
				}
			}
		}
		if(dist[N] < T)
			return true;
		else
			return false; 
	}
	void resolve(){
		if(!SPFA((1000000001))){  //ͼ����ͨ ֱ���˳� 
			cout << "AFK";
        	return;
		}
		while (L <= R){
			int mid = (L+R)/2;
			if (SPFA(mid)) R=mid-1;
			else
				L = mid+1;
		}
		cout << L << endl;
	} 
};
int main(){	
	node test;
	test.resolve();
	return 0;
}
