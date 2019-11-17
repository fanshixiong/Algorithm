#include<bits/stdc++.h>

using namespace std;
const int maxn = 2e5+10;
pair<int, int> a[maxn];
int dp[maxn], tp[maxn], ans[maxn];
int n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i].first;
		a[i].second=i;
	}
	sort(a+1, a+1+n);
	dp[3] = a[3].first-a[1].first;
	int cnt=-1;
	int minx = 1e9;
	for(int i=4; i<=n; i++){
		if(i>=6 && minx > dp[i-3]-a[i-2].first){
			minx = dp[i-3]-a[i-2].first;
			cnt = i-2;
		}
		dp[i] = dp[i-1]+a[i].first-a[i-1].first;
		tp[i]=tp[i-1];
		if(minx+a[i].first<dp[i]){
			dp[i]=minx+a[i].first;
			tp[i]=cnt;
		}
	}
	int tmp=tp[n], pos=1;
	for(int i=n; i>=1; i--){
		ans[a[i].second]=pos;
		if(tmp==i){
			pos++;
			tmp=tp[i-1];
		}
	}
	cout << dp[n] << " " << pos<< endl;
	for(int i=1; i<=n; i++)
		cout << ans[i] << " ";
	return 0;
}
