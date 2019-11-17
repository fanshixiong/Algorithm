#include<iostream> 
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
int n,m;
vector<int> pos(105), cure(105);//pos: -1    cure: 1  binary
queue<int> q;
int update(int x, int k){
	x &= (~cure[k]); //cure[k]ȡ������������Ϊ1�������κò���Ϊ0����ôx��cure[k]��Ϊ1�ſ��Ի��� 
	x |= pos[k];  //x��pos[k]��һ��Ϊ1˵�����ֲ��ͻỼ�� 
	return x;
}
int main(){
	cin >> n >> m;
	for(int i=1; i<=m; i++){
		for(int j=0; j<n; j++){
			int x; cin >> x;
			if(x==1)
				cure[i] |= (1<<j);
			else if(x==-1)
				pos[i] |= (1<<j);
		}
	}
	int beg = (1<<n)-1; //��ʼ���ж����� 
	vector<int> dist(1<<n, 0x3f3f3f3f), vis((1<<n)+5);
	q.push(beg); 
	vis[beg]=1;
	dist[beg]=0;
	//spfa
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0; 
		for(int i=1; i<=m; i++){
			int v=update(u, i);
			if(dist[v]>dist[u]+1){
				dist[v]=dist[u]+1;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	if(dist[0] == 0x3f3f3f3f)
		cout << "The patient will be dead." <<endl;
	else
		cout << dist[0] <<endl;
	return 0;
}
