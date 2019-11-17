#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
vector<int> parent(10005);
int n, m, p, t;
struct edge{
	double dist;
	int beg, end;
};
vector<edge> T(1000005);
int Find(int x){
	if(x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}
bool cmp(edge &a, edge &b){
	return a.dist < b.dist;
}
void kruskal(){
	double ans = 0;
	int cnt=0;
	sort(T.begin(), T.begin()+t, cmp);
	for(int i=0; i<t; i++){
		int x = Find(T[i].beg);
		int y = Find(T[i].end);
		if(x != y && cnt++ < n-p){        //Ìõ¼şÅĞ¶Ï 
			parent[Find(x)] = T[i].end;
			ans = max (ans, T[i].dist);
		}
	}
	printf("%.2f", ans);
}
int main(){
	cin >> p >> n;
	vector<double> X(1005), Y(1004);
	for(int i=1; i<=n; i++){
		cin >> X[i] >> Y[i];
	}
	t=0;
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			double d = sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
			T[t].dist=d; T[t].beg=i; T[t].end=j;
			t++;
		}
	}
	for(int i=1; i<=n; i++)
		parent[i]=i;
	kruskal();
	return 0;
}
