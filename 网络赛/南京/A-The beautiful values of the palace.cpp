#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 2e6+10;

struct node{
	ll type;
	ll id, x, y;
	node(){}
	node(ll x, ll y, ll type, ll id):x(x), y(y), type(type), id(id){}
}Q[maxn];
bool cmp(node a, node b){
	if(a.x == b.x && a.y == b.y){
		if(!b.type) return 0;
		else return 1;
	}
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

ll tree[maxn];
ll ans[maxn];
ll n, m, q;
void add(int x, ll c){
	if(!x) return;
	for (int i=x; i<=maxn; i+=i&(-i)){
		tree[i] += c;
	}
}
ll sum(int x){
	ll ans = 0;
	for (int i=x; i; i-=(i&(-x))){
		ans += tree[i];
	}
	return ans;
}
ll change(ll x, ll y, ll n){
	swap(x, y);
	ll q= min(min(x, n-x+1), min(y, n-y+1)); //???
	ll num = n*n-((n/2-q+1)*2+1)*((n/2-q+1)*2+1);
	ll anss = 0;
	if(n-y+1==q)
		anss = num+(n-x+1)-(q-1);
	else if(x == q)
		anss = num + n-(q-1)*2+n-y+1-(q-1); // ???
	else if(y==q){
		anss = num+(n-(q-1)*2-1)*2+x-(q-1);
	}
	else 
		anss = num+(n-(q-1)*2-1)*3+y-(q-1);
	ll ans = 0;
	while(anss){
		ans += anss%10;
		anss /= 10;
	}
	return ans;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%lld %lld %lld", &n, &m, &q);
		for (int i=0; i< maxn; i++){
			tree[i] = ans[i] = 0;
		}
		for(int i=1; i<=m; i++){
			scanf("%lld%lld" , &Q[i].x, &Q[i].y);
			Q[i].type = 0;
		}
		ll tot = m;
		for(int i=1; i<=q; i++){
			ll x1, y1, x2, y2;
			scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
			Q[++tot] = node(x2, y2, 1, i);
			Q[++tot] = node(x1-1, y1-1, 1, i);
			Q[++tot] = node(x1-1, y2, -1, i);
			Q[++tot] = node(x2, y1-1, -1, i);
		}
		sort(Q+1, Q+1+tot, cmp);
		for(int i=1; i<=tot; i++){
			if(!Q[i].type)
				add(Q[i].y, change(Q[i].x, Q[i].y, n));
			else
				ans[Q[i].id] += Q[i].type * sum(Q[i].y);
		}
		for(int i=1; i<=q; i++){
			printf("%lld\n", ans[i]);
		}
	}
	return 0;
}
