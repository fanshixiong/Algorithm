 //莫队算法模板：
//变的是Add和Del函数 

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<bitset>
using namespace std;
const int N = 100000;
struct node{
	int op, l, r, y, id;
}Q[N+5];
int cnt[N+5], pos[N+5], ans[N+5], num[N+5];
int n, m, k;
int L=1, R=0, Ans=0;
bitset<N+5> now1, now2;
bool cmp(node &a, node &b){
	if(pos[a.l] == pos[b.l])
		return a.r < b.r;
	return pos[a.l] < pos[b.l]; 
}
void Add(int x){
	if(cnt[x]++ == 0){
		now1[x]=1;
		now2[N-x]=1;
	}
}
void Del(int x){
	if(--cnt[x] == 0){
		now1[x]=0;
		now2[N-x]=0;
	}
}
void init(){
	cin >> n >> m;
	int sz=sqrt(n);
	for(int i=1; i<=n; i++){
		cin >> num[i];
		pos[i]=i/sz;
	}
	for(int i=1; i<=m; i++){
		cin >> Q[i].op >> Q[i].l >> Q[i].r >> Q[i].y;
		Q[i].id=i;
	}
	cnt[0]=1;
	sort(Q+1, Q+m+1, cmp);
	now1.reset();
	now2.reset();
}
int main(){
	init();
	for(int i=1; i<=m; i++){
		while(L<Q[i].l){
			Del(num[L]);
			L++;
		}
		while(L>Q[i].l){
			L--;
			Add(num[L]);
		}
		while(R<Q[i].r){
			R++;
			Add(num[R]);
		}
		while(R>Q[i].r){
			Del(num[R]);
			R--;
		}	
		int opt = Q[i].op, x = Q[i].y;
		switch(opt){
			case 1:{
				if((now1 & (now1<<x)).any())
					ans[Q[i].id]=1;
				break;
			}
			case 2:{
				if((now1 & (now2>>(N-x))).any())
					ans[Q[i].id]=1;
				break;
			}
			case 3:{
				for(int j=1; j*j<=x; j++){
					if(!(x%j)){
						if(now1[j] && now1[x/j]){
							ans[Q[i].id]=1;
							break;
						}
					}
				}
				break;
			}
		}
	}
	for(int i=1; i <= m; i++){
		if(ans[i])
			cout << "hana" << endl;
		else
			cout << "bi" << endl;
	}
	return 0;
}
