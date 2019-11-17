#include<iostream>
#include<vector>
using namespace std;
int ans=0;
vector<vector<int> > maze(3, vector<int>(6));
vector<int> vis(11);
bool judge(int x, int y, int n){
	if(x==2 && n<=maze[1][y])
		return false;
	if(y>1 && n<=maze[x][y-1])
		return false;
	return true;
}
void dfs(int x, int y){
	if(x==2 && y==5) {
		ans++;
		for(int i=1; i<=2; i++){
			for(int j=1; j<=5; j++){
				cout << maze[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}
	if(y==6){
		dfs(x+1, 1);
		return;
	}
	for(int i=2; i<=9; i++){
		if(!vis[i] && judge(x, y, i)){
			vis[i]=1;
			maze[x][y]=i;
			dfs(x, y+1);
			vis[i]=0;
		}
	}
}
int main(){
	maze[1][1]=1; vis[1]=1;
	maze[2][5]=10; vis[10]=1;
	dfs(1, 2);
	cout << ans << endl;
	return 0;
} 
