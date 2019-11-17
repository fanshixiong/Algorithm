#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
vector<int> par;
int n, m;
struct node{
	int x, y;
	long long resent;
};
int Find(int x){
	if(x==par[x])
		return x;
	return par[x] = Find(par[x]);
}
struct cmp{                                            //************
	bool operator ()(node &a, node &b){
		return a.resent < b.resent;
	}
};
int main(){
	cin >> n >> m;
	par.resize(n+1);
	priority_queue<node, vector<node>, cmp> Crime;        //**********
	for(int i=1; i<=n; i++)
		par[i]=i;
	for(int i=0; i<m; i++){
		int q, w;long long e;
		cin >> q >> w >>e;
		node tp; 
		tp.x=q; tp.y=w; tp.resent=e;
		Crime.push(tp);
	//	cout << Crime.top().x<<" "<<Crime.top().y << " " << Crime.top().resent << endl;
	}
	vector<int> Enemy(n+1);
	while(!Crime.empty()){
		int enemy1=Crime.top().x;
		int enemy2=Crime.top().y;
		//cout << enemy1 <<" "<<enemy2 << " " << Crime.top().resent << endl;
		if(Find(enemy1)==Find(enemy2)){
			cout << Crime.top().resent;
			return 0;
		}
		if(!Enemy[enemy1])
			Enemy[enemy1]=enemy2;
		else
			par[Find(Enemy[enemy1])]=Find(enemy2);
		if(!Enemy[enemy2])
			Enemy[enemy2]=enemy1;
		else
			par[Find(Enemy[enemy2])]=Find(enemy1);
		Crime.pop();
	}
	cout << 0 << endl;
	return 0;
} 
