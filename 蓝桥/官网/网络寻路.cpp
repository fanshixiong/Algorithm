#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<vector<int> > Path(100010);
vector<bool> vis(10010);
int n;
int res = 0; 
void dfs(int k, int step){
	//cout << step << " ";
	if (step == 3){                          //别人的想法 
		res+=Path[k].size()-1;
		return;
	}
	if (step == 4){                          //我的想法 
		res++;
		return;
	}
	for (int i = 0; i < Path[k].size(); i++){
		if(!vis[Path[k][i]]){
			vis[Path[k][i]]=1;
			dfs(Path[k][i], step+1);
			vis[Path[k][i]]=0;
		}
	}
}
int main(){
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		Path[x].push_back(y);
		Path[y].push_back(x);  
	}
	for (int i = 1; i <= n; i++){
		vis[i]=1;
		dfs(i, 1);
		vis[i]=0;
	}
	cout << res << endl;
	return 0; 
}
