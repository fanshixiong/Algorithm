#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
int bit[1000005], num[1000005], vis[1000005];
int n;
struct node{
	int l, r;
	int pos;
}quer[1000005];
bool cmp(node &a, node &b){
	return a.r == b.r ? a.l < b.l : a.r<b.r;
}
int lowbit(int x){
	return x&(-x);
}
void add(int x, int k){
	while(x<=n){
		bit[x]+=k;
		x+=lowbit(x);
	}
}
int sum(int x){
	int ans=0;
	while(x){
		ans += bit[x];
		x -= lowbit(x);
	}
	return ans;
}
int query(int a, int b){
	return sum(b) - sum(a-1);
}
int main() {
	ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1; i<=n; i++){
    	cin >> num[i];
	}
	int m; cin >> m;
	for(int i=1; i<=m; i++){
		cin >> quer[i].l >> quer[i].r;
		quer[i].pos=i;
	}
	sort(quer+1, quer+m+1, cmp);
	vector<int> ans(m+1);
	int tmp=1;
	for(int i=1; i<=m; i++){
		for(int j=tmp; j<=quer[i].r; j++){
			if(vis[num[j]]){
				add(vis[num[j]], -1);
			}
			add(j, 1);
			vis[num[j]]=j;
		}
		ans[quer[i].pos] = query(quer[i].l, quer[i].r);
		tmp=quer[i].r+1;
	}
	for(int i=1; i<=m; i++){
		cout << ans[i] <<endl;
	}
	return 0;
}
