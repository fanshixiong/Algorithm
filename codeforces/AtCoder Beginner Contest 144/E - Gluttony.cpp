#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5+10;
ll n, k;
ll a[maxn], f[maxn];
bool cmp(ll a, ll b){
	return a>b;
}
bool judge(ll x){
	ll ans=0;
	for(int i=0; i<n; i++){
		if(a[i]*f[i] > x){
			ans += a[i]-x/f[i];
		}
	}
	return ans <= k;
}
int main(){
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for(int i=0; i<n; i++)
		cin >> a[i];
	for(int i=0; i<n; i++)
		cin >> f[i];
	sort(a, a+n);
	sort(f, f+n, cmp);
	ll l=-1, r=1e12+10;
	while(abs(r-l) > 1){
		ll mid = (l+r)/2;
		if(judge(mid)){
			r=mid;
		}
		else
			l=mid;
	}
	cout << r << endl;
	return 0;
}
