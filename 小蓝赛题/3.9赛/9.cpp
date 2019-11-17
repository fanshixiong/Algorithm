#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dist[2][2]={1, 0, -1, 1};
vector<vector<int> > num(100, vector<int>(1000));
vector<vector<int> > vis(100, vector<int>(1000));
int m, n, cnt=0;
string s;
void dfs(int x, int y, int d){
	if(cnt==s.size()-1) return;
	int x1=dist[d][0]+x;
	int y1=dist[d][1]+y;
	if(x1<0||y1<0||x1>=m||vis[x1][y1]){
		if(d==0) d=1;
		else d=0;
		dfs(x, y, d);
	}
	else if(x1>=0&&y1>=0&&x1<m&&!vis[x1][y1]){
		num[x1][y1] = ++cnt;
		vis[x1][y1]=1;
		dfs(x1, y1, d);
	}
}
int main(){
	cin >> s;
	cin >> m;
	vis[0][0]=1;
	dfs(0, 0, 0);
	cout<<s[0];
	for(int i=0; i<m; i++){
		for(int j=0; j<100; j++)
			if(num[i][j]!=0)		
				cout << s[num[i][j]];
	}
	return 0;
} 
