#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e3+10;
int t[maxn], w[maxn];
int n;
int p[maxn];
bool cmp(const int a, const int b){
	return t[a] == t[b] ? w[a] > w[b] : t[a] > t[b];
}
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> t[i];
	for(int i = 1; i <= n; i++) cin >> w[i];

	for(int i = 1; i <= n; i++) p[i] = i;
	sort(p + 1, p + 1 + n, cmp);

	int ans = 0, pre = 0, pre_i = ;
	t[n+1] = 0;
	for(int i = n; i >= 1; i--){
		int x = p[i]; 
		pre += t[pre_i] - t[x];
		pre_i = x;
		//cout << pre << endl;
		if(pre == 0) ans -= w[x];
		else{
			ans += w[x];
			pre--;
		}
	}
	cout << ans << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

/*
1
4
1 3 3 3
3 2 3 4

*/