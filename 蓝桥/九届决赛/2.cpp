#include<iostream>
#include<vector>
using namespace std;
int ans=0;
vector<vector<int> > maze(5, vector<int>(5));
vector<int> vis(17);
vector<int> row(5), col(5), lie(5);
bool judge(){
	for(int i=1; i<=4; i++){
		for(int j=1; j<=4; j++){
			if(i==j)	
				lie[1]+=maze[i][j];
			if(5-i==j || 5-j==i)
				lie[2]+=maze[i][j];
		}
	}
	for(int i=1; i<=4; i++){
		if(row[i]!=34 || col[i]!=34)
			return false;
	}
	if(lie[1]!=34 || lie[2]!=34)
		return false;
	return true;
}
void dfs(int x, int y){ cout << x << " " <<y << endl;
	if(row[x]>34 || col[y]>34) return;
	if(x==4 && y==5) {
		if(judge()){
			ans++;
			for(int i=1; i<=4; i++){
				for(int j=1; j<=4; j++){
					cout << maze[i][j] << " ";
				}
				cout << endl;
			}
		}
		return;
	}
	if(y==5){
		dfs(x+1, 1);
		return;
	}
	for(int i=16; i>=2; i++){
		if(!vis[i] && row[x]+i<=34 && col[y]+i<=34){
			vis[i]=1;
			maze[x][y]=i;
			row[x]+=maze[x][y];
			col[y]+=maze[x][y];
			dfs(x, y+1);
			row[x]-=maze[x][y];
			col[y]-=maze[x][y];
			vis[i]=0;
		}
	}
}
int main(){
	maze[1][1]=1; vis[1]=1;
	row[1]+=1; col[1]+=1;
	dfs(1, 2);
	cout << ans << endl;
	return 0;
} 
