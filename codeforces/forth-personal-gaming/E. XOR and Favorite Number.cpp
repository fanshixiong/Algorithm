#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1<<20;

struct node{
	int l, r, id;
}Q[maxn];

int pos[maxn];
ll ans[maxn];
ll sum[maxn];
int pre[maxn];

bool cmp(node a , node b){
	if(pos[a.l] == pos[b.l])
		return a.r < b.r;
	return pos[a.l] < pos[b.l]; 
}

ll Ans=0;
int n, m, k;
int L=1, R=0;
void Add(int x){
	Ans += sum[pre[x]^k];
	sum[pre[x]]++;
}
void Del(int x){
	sum[pre[x]]--;
	Ans -= sum[pre[x]^k];
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	int sz = sqrt(n);
	for(int i=1; i<=n; i++){
		scanf("%d", &pre[i]);
		pre[i] = pre[i-1]^pre[i];
		pos[i] = i/sz;
	}
	for(int i=1; i<=m; i++){
		scanf("%d%d", &Q[i].l, &Q[i].r);
		Q[i].id = i;
	}
	sort(Q+1, Q+1+m, cmp);
	sum[0]=1;
	for(int i=1; i<=m; i++){
		while(L < Q[i].l){
			Del(L-1);
			L++;
		}
		while(L > Q[i].l){
			L--;////
			Add(L-1);
		}
		while(R < Q[i].r){
			R++;
			Add(R);
		}
		while(R > Q[i].r){
			Del(R);
			R--;
		}
		ans[Q[i].id] = Ans;
	}
	for(int i=1; i<=m; i++){
		cout << ans[i] << endl;
	}
	return 0;
}
