#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Edges{
	int x,y,w;
	Edges(int a, int b, int c){
		x = a; y = b; w = c;
	}
};
vector<int> parents;
void Init(){
	for (int i = 1; i <= parents.size(); i++)
		parents[i] = i;
}

int Find(int x){
	if (parents[x] == x)
		return x;
	else
		return parents[x] = Find(parents[x]); 
}
bool Union(int x, int y){
	x = Find(x);
	y = Find(y);
	if(x != y){
		parents[x] = y;
		return 1;
	}
	return 0;
}
bool cmp(Edges a, Edges b){
	return a.w > b.w;
}
int main(){
	int m, n;
	cin >> m >> n;
	parents.resize(m+1);
	vector<Edges> edges;
	int a, b, c;
	for(int i = 0; i < n; i++){
		cin >> a >> b >>c;
		Edges tmp(a, b, c);
		edges.push_back(tmp);
	} 
	Init();
	sort(edges.begin(), edges.end(), cmp);
	int res = 0, pre = -1;
	for (int i = 0; i < n; i++){
		int way = Union (edges[i].x, edges[i].y);    //如果两个点之前不连通，则 抗议天数加一 
		if (way && pre != edges[i].w){       //两个点之前不连通 且 不是同一天坏， 天数不同 
			res++;
			pre = edges[i].w;
		/*	for (int i = 1; i < parents.size(); i++){
					cout << parents[i] << " " ;
			}
			cout << endl; 	*/
		}
	}
/*	for (int i = 1; i < parents.size(); i++){
		cout << parents[i] << " " ;
	} */
	cout << res << endl;
	return 0;
}
