#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long 
#define Max 400010
using namespace std;
struct node{
	ll add, mul, v;
}ans[Max];
unsigned ll n, m, d, num[Max];
void build(ll p, ll l, ll r){
	ans[p].mul=1;
	ans[p].add=0;
	if(l == r){
		ans[p].v= num[l];
	}
	else{
		ll m=(r+l)>>1;
		build(p<<1, l, m);
		build(p<<1|1, m+1, r);
		ans[p].v=ans[p<<1].v+ans[p<<1|1].v;
	}
	ans[p].v %= d;
}
void push_down(ll p, ll l ,ll r){
	int m=(l+r)>>1;
	ans[p<<1].v=(ans[p<<1].v*ans[p].mul+ans[p].add*(m-l+1))%d;
	ans[p<<1|1].v=(ans[p<<1|1].v*ans[p].mul+ans[p].add*(r-m))%d;
	
	ans[p<<1].mul=(ans[p<<1].mul*ans[p].mul)%d;
	ans[p<<1|1].mul=(ans[p<<1|1].mul*ans[p].mul)%d;
	
	ans[p<<1].add=(ans[p<<1].add*ans[p].mul+ans[p].add)%d;
	ans[p<<1|1].add=(ans[p<<1|1].add*ans[p].mul+ans[p].add)%d;
	
	ans[p].mul=1;
	ans[p].add=0;
	return;
}
void update1(ll p, ll x, ll y, ll l, ll r, ll k){
	if(r<x || l > y)
		return;
	if(l <= x && y <= r){
		ans[p].v = (ans[p].v*k)%d;
		ans[p].mul = (ans[p].mul*k)%d;
		ans[p].add = (ans[p].add*k)%d;
		return;
	}
	
	push_down(p, x, y);
	ll m=(x+y)>>1;
	update1(p<<1, x, m, l, r, k);
	update1(p<<1|1, m+1, y, l, r, k);
	
	ans[p].v = (ans[p<<1].v+ans[p<<1|1].v)%d;
	return;
}
void update2(ll p, ll x, ll y, ll l ,ll r, ll k){
	if(r < x || y < l){
		return;
	}
	if(l <= x && y <= r){
		ans[p].add = (ans[p].add+k)%d;
		ans[p].v = (ans[p].v+k*(y-x+1))%d;
		return;
	}
	
	push_down(p, x, y);
	ll m=(x+y)>>1;
	update2(p<<1, x, m, l, r, k);
	update2(p<<1|1, m+1, y, l, r, k);
	ans[p].v = (ans[p<<1].v+ans[p<<1|1].v)%d;
	return;
}
ll query(ll p, ll x, ll y, ll l, ll r){
	if(r < x || y < l)
		return 0;
	if(l<=x && y<=r){
		return ans[p].v;
	}
	push_down(p, x, y);
	ll m=(x+y)>>1;
	return (query(p<<1, x, m, l, r) + query(p<<1|1, m+1, y, l ,r))%d;
}
int main(){
	cin >> n>> m>> d;
	for(int i=1; i<=n; i++)
		cin >> num[i];
	build(1, 1, n);
	while(m--){
		int x; cin >> x;
		if(x==1){
			ll a, b, c;
			cin >> a >> b >> c;
			update1(1, 1, n, a, b, c);
		}
		else if(x==2){
			ll a , b, c;
			cin >> a >> b >> c;
			update2(1, 1, n, a, b, c);
		}
		else{
			ll a, c;
			cin >> a >> c;
			cout << query(1, 1, n, a, c)<<endl;;
		}
	}
	return 0;
} 
