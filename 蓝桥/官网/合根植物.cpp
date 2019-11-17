#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
vector<int> par(1000005);
int m, n;
int Find(int x){
	if(x==par[x])
		return x;
	return par[x]=Find(par[x]);
}
bool Union(int x, int y){
	int x1=Find(x);
	int y1=Find(y);
	if(x1==y1)
		return true;
	else{
		par[x1]=y1;
		return false;
	}
}
int main(){
	cin >> m >> n;
	for(int i=1; i<=m*n; i++)
		par[i]=i;
	int k;cin >> k;
	for(int i=1; i<=k; i++){
		int x, y;
		cin >> x >> y;
		Union(x, y);
	}
	int ans=0;
	//vector<int> vis(m*n+1);
	for(int i=1; i<=m*n; i++){
		if(par[i]==i){
			ans++;
		}
		//cout << par[i] << " ";
	}
	cout << ans <<endl;
	return 0;
}
