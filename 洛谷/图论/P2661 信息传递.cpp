//Topo排序： 

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> G(200010);
bool vis[200010]={0};
bool judge[200010]{0};          //判断是否已经遍历过 
vector<int> path(200010);    //记录该节点第一次出现时的步数 
int n, ans = 0x3f3f3f3f;
void dfs(int k, int step){
	if(judge[k]) return;
	if(vis[k]){
		//cout << k << " " << step << endl;
		ans=min(ans, step-path[k]);
		return;
	}
	vis[k]=1;
	int t = G[k];
	path[k]=step;
	dfs(t, step+1);
	judge[k]=true;
	
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> G[i];
	}
	for (int i = 1; i <= n; i++){
		dfs(i, 0);
	}
	cout << ans << endl;
	return 0;
} 
