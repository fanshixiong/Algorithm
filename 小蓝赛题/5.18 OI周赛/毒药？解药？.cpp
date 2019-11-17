#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<vector<int> > position(101, vector<int>(15));
struct node{
	int num, pos;
	node(int x, int y){
		num=x; pos=y;
	}
};
vector<node> sum;
bool cmp(node &a, node &b){
	return a.num > b.num;
}
int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int x=0;
		for(int j=0; j<n; j++){
			cin >> position[i][j];
			if(position[i][j]==1)
				x++;
		}
		node tmp(x, i);
		sum.push_back(tmp); 
	}
	sort(sum.begin(), sum.end(), cmp);
	int ans=0;
	vector<int> vis(n+1);
	bool b=0;
	for(int i=0; i<m; i++){
		int t=sum[i].pos;
		ans++;
		for(int j=0; j<n; j++){
			if(position[t][j]==1)
				vis[j]+=200;
			else if(position[t][j]==-1)
				vis[j]-=20;
		}
		int j=0;
		for(; j<n; j++){
			if(vis[j]<=0)
				break;
		}
		if(j==n){
			b=1;
			break;
		}
	}
	if(b)
		cout << ans << endl;
	else 
		cout << "The patient will be dead." << endl; 
	return 0;
} 
