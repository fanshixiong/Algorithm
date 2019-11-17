#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5+5;
struct node{
	int l, r;
}a[maxn];
bool cmp (node &a, node &b){
	return a.l > b.l;
}
ll s, n;

bool judge(int x){
	ll tmp=0, mid=n/2+1, cnt=0;
	for(int i=0; i<n; i++){
		if(cnt < mid && a[i].r >= x){
			tmp += max(a[i].l, x);
			cnt++;
		}
		else
			tmp += a[i].l;
	}
	return (cnt==mid) && (tmp<=s);
}
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >>t;
	while(t--){
		cin >> n >> s;
		for(int i=0; i<n; i++){
			cin >> a[i].l >> a[i].r;
		}
		sort(a, a+n, cmp);
		int left =0, right = 1e9, ans=-1;
		while(left <= right){
			int mid = (right+left)/2;
			if(judge(mid)){
				ans = mid;
				left = mid+1;
			}
			else
				right = mid-1;
		}
		cout << ans << endl;
	}
	return 0;
}
