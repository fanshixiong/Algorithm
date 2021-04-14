#include<bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
#define ll long long
const int maxn = 55;
const ll mod = 20210101;
int dist[maxn][maxn];
int a[maxn][maxn];
vector<int> nums[300];
int main(){
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> a[i][j];

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			nums[a[i][j]].push_back(i * n + j);
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int u = i * n + j;
			for(int p = 1; p <= n; p++){
				for(int q = 1; q <= n; q++){
					if(i == p && q == j) continue;
					int w = p * n + q;
					dist[u][w] = dist[w][u] = abs(i-p) + abs(j-q);
				}
			}
		}
	}


	int ans = -1, pre = 0;
	for(int i = 1; i <= k; i++){
		int mi = 0x3f3f3f3f;
		// cout << i << endl;
		for(auto c : nums[i]){
			// cout << c << " ";
			if(mi > dist[c][pre]){
				mi = dist[c][pre];
				pre = c;
			}
		}
		// cout << endl;
		if(mi == 0x3f3f3f3f){
			cout << -1 << endl;
			return 0;
		}
		if(ans == -1) ans = mi;
		else ans += mi;
	}
	cout << ans << endl;
	return 0;
}
/*
2 2 
1 2
2 1

4 4
1 2 2 1
2 4 4 1
4 4 4 2
1 1 1 2
*/