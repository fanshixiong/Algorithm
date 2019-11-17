#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
using namespace std;
int main(){
	int n; cin >> n;
	vector<int> time(n+1);
	vector<vector<int> > pre(n+1);
	for(int i=1; i<=n; i++){
		int y, x; 
		cin >> y >> time[i];
		cin >> x;
		while(x!=0){
			pre[i].push_back(x); 
			cin >> x; 
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		int tmp=0;
		for(int j=0; j<pre[i].size(); j++){
			tmp = max(time[pre[i][j]], tmp);      //每次找准备任务中花时间最大的任务 
		}
		time[i]+=tmp;
		ans=max(ans, time[i]);
		//cout << time[i] << " ";
	}
	cout << ans << endl;
	return 0;
} 
