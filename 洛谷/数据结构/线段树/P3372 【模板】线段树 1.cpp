#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define Max 100010
using namespace std;
unsigned ll n, m, tag[Max<<2], ans[Max<<2], num[Max];
void push_up(ll p){
	ans[p] = ans[p<<1] + ans[p<<1|1]; 
}
void build(ll p, ll l, ll r){
	tag[p]=0;
	if(l==r){
		ans[p]=num[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(p<<1, l, mid);
	build(p<<1|1, mid+1, r);
	push_up(p);
}
void f(ll p, ll l, ll r, ll k){
	tag[p] = tag[p] + k;
	ans[p] = ans[p] + k*(r-l+1);
}
void push_down(ll p, ll l , ll r){
	ll mid=(l+r)>>1;
	f(p<<1, l, mid, tag[p]);
	f(p<<1|1, mid+1, r, tag[p]);
	tag[p]=0;
}
void update(ll lx, ll rx, ll l, ll r, ll p, ll k){
	if(lx <= l && r <= rx){ //说明在区间中 
		ans[p] += k*(r-l+1);
		tag[p] += k;
		return; 
	}
	push_down(p, l, r);
	ll mid = (l+r) >> 1;
	if(lx <= mid) update(lx, rx, l, mid, p<<1, k);
	if(rx > mid) update(lx ,rx, mid+1, r, p<<1|1, k);
	push_up(p);
}
ll query(ll x, ll y, ll l, ll r, ll p){
	ll res = 0;
	if (x<=l && r <= y) //在区间中
		return ans[p];  
	ll mid = (l+r)>>1;
	push_down(p, l, r);
	if(x<=mid) 
		res += query(x, y, l, mid, p<<1);
	if(y>mid) 
		res += query(x, y, mid+1, r, p<<1|1);
	return res; 
}
int main(){
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(ll i=1; i<=n; i++)
		cin >> num[i];
	build (1, 1, n);
	while(m--){
		int x; cin >> x;
		if(x==1){
			ll a, b, c; cin >> a >> b >>c;
			update(a, b, 1, n, 1, c);
		}
		else{
			ll a, b;
			cin >> a >> b;
			cout << query(a, b, 1, n, 1) << endl;
		}
	}
	return 0;
}
