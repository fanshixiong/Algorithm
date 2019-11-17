//莫队算法模板：
//变的是Add和Del函数 

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 500005;
struct node{
	int l, r, id;
}Q[N];
int cnt[N], pos[N], ans[N], num[N];
int n, m, k;
int L=1, R=0, Ans=0;
bool cmp(node &a, node &b){
	if(pos[a.l] == pos[b.l])
		return a.r < b.r;
	return pos[a.l] < pos[b.l]; 
}
void Add(int x){
	int y = ++cnt[num[x]];
	Ans += 2*y-1;
}
void Del(int x){
	int y = --cnt[num[x]];
	Ans -= 2*y+1;
}
int main(){
	cin >> n >> m >> k;
	int sz=sqrt(n);
	for(int i=1; i<=n; i++){
		cin >> num[i];
		pos[i]=i/sz;
	}
	for(int i=1; i<=m; i++){
		cin >> Q[i].l >> Q[i].r;
		Q[i].id=i;
	}
	cnt[0]=1;
	sort(Q+1, Q+m+1, cmp);
	for(int i=1; i<=m; i++){
		while(L<Q[i].l){
			Del(L);
			L++;
		}
		while(L>Q[i].l){
			L--;
			Add(L);
		}
		while(R<Q[i].r){
			R++;
			Add(R);
		}
		while(R>Q[i].r){
			Del(R);
			R--;
		}	
		ans[Q[i].id] = Ans;
	}
	for(int i=1; i <= m; i++){
		cout << ans[i] <<endl; 
	}
	return 0;
}
