#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct node{
	int beg, end, cost;
	node(){
		beg=end=cost=0;
	}
};
bool cmp(node &a, node &b){
	return a.cost < b.cost;
}
class City{
	vector<node> G;
	int n;
	vector<int> par;
	int ans1, ans2;
public:
	City(){
		ans1=ans2=0;
		int m;
		cin >> n >> m;
		par.resize(n+1); 
		for (int i=1; i<=m; i++){
			int x,y, z;
			cin >> x >> y >> z;
			node tmp;
			tmp.beg=x; tmp.end=y;tmp.cost=z;
			G.push_back(tmp); 
		}
		
		for(int i=1; i<=n; i++){
			node tmp;
			tmp.beg=0; tmp.end=i; cin>>tmp.cost;
			//cout << tmp.cost <<endl;
			if(tmp.cost==-1)
				tmp.cost = -0x3f3f3f3f;
			G.push_back(tmp); 
		}
		sort(G.begin(), G.end(), cmp);
	}
	int Find (int x){
		if(x == par[x])
			return x;
		return par[x]=Find(par[x]);
	}
	void Kruskalone(){                             //has dock  
		for (int i = 1; i<=n; i++){
			par[i]=i;
		}
		for(int i=0; i<G.size(); i++){
			if(G[i].cost == -0x3f3f3f3f) continue;
			if(Find(G[i].beg) != Find(G[i].end) || G[i].cost<0){
				ans1 += G[i].cost;
				par[Find(G[i].beg)]=Find(G[i].end);
			}
		}
	}
	void Kruskaltwo(){                       //not has dock
		for (int i=1; i<=n; i++)
			par[i]=i;
		for(int i=0; i<G.size(); i++){
			if(G[i].beg==0) continue;
			if(Find(G[i].beg) != Find(G[i].end) || G[i].cost<0){
				ans2 += G[i].cost;
				par[Find(G[i].beg)]=Find(G[i].end);
			}
		}
	}
	void resolve(){
		Kruskalone();
		Kruskaltwo();
		int x=0;
		for(int i=1; i<=n; i++)
			if(par[i]==i)
				x++;
		if(x!=1)                                   //no dock not unicom
			cout << ans1 << endl;
		else                                        //has dock
			cout << min(ans1, ans2) << endl;
	}
};
int main(){
	City test;
	test.resolve();
	return 0;
} 
