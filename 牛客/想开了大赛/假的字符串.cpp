#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N = 1e4+5;
int tree[N][27], vis[N], indeg[27];
string s[N], ans[N];
int cnt=0, n;
vector<vector<int> > G(27);
void insert(string s){
	int pos=0;
	for(int i=0; i<s.size(); i++){
		int x=s[i]-'a';
		if(!tree[pos][x])
			tree[pos][x] = ++cnt;
		pos=tree[pos][x];
	}
	vis[pos]=1;
}
bool topo(){
	queue<int> q;
	int res=0;
	for(int i=0; i<26; i++){
		if(!indeg[i]){
			q.push(i);
			res |= (1<<i);
		}
	}
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=0; i<G[t].size(); i++){
			int v=G[t][i];
			indeg[v]--;
			if(!indeg[v]){
				q.push(v);
				res |= (1<<v);
			}
		}
	}
	return res == (1<<26)-1;
}
bool judge(string s){
	int p=0;
	memset(indeg, 0, sizeof(indeg));
	for(int i=0; i<26; i++) G[i].clear();
	for(int i=0; i<s.size(); i++){
		int x=s[i]-'a';
		for(int j=0; j<26; j++){
			if(tree[p][j] && j!=x){
				indeg[j]++;
				G[x].push_back(j);
				G[j].push_back(x);
			}
		}
		if(vis[p]) return 0;
		p = tree[p][x];
	}
	return topo();
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> s[i];
		insert(s[i]);
	}
	int res=0;
	for(int i=0; i<n; i++){
		if(judge(s[i])){
			ans[res++]=s[i];
		}
	}
	cout << res << endl;
	for(int i=0; i<res; i++){
		cout << ans[i] << endl;
	}
	return 0;
}
