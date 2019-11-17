#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
struct node{
	int y, id;
	node(int y, int id):y(y), id(id){}
};
vector<node> v[maxn];
vector<int> ans;
bool operator<(node a, node b){
	if(a.y != b.y)
		return a.y < b.y;
	else return a.id < b.id;
}
int main(){
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	int x, y;
	for(int i=1; i<=n; i++){
		cin>>x >> y;
		v[x].push_back(node(y, i));
	}
	set<node> s;
	for(int i=1; i<maxn; i++){
		while(s.size() && (*s.begin()).y<i)
			s.erase(s.begin());
		for(int p=0; p<v[i].size(); p++){
			//cout << v[i].size() << " ";
			s.insert(v[i][p]);
		}
		//cout << endl;
		//cout <<"SS" << endl;
		while(s.size() > k){
			ans.push_back((*s.rbegin()).id);
			s.erase(*s.rbegin());
		}
	}
	//sort(ans.begin(), ans.end());
	cout <<ans.size() << endl;
	for(int i=0; i<ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
} 
