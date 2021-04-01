#include<bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
vector<pi> points;
int main(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		points.push_back({x, y});
	}

	unordered_map<int, int> he, sh, x1, x2;
	int ans = 0;
	for(auto c : points){
		int x = c.first, y = c.second;
		he[x]++; sh[y]++;
		x1[x-y]++; x2[y+x]++;
		ans = max(ans, he[x]);
		ans = max(ans, sh[y]);
		ans = max(ans, x1[x-y]);
		ans = max(ans, x2[x+y]);
	}

	for(auto c : points){
		int x = c.first, y = c.second;
		double top = 1.0 * y + n - 0.5;
		double bot = 1.0 * y - n - 0.5;
		double lef = 1.0 * x - n - 0.5;
		double rig = 1.0 * x + n - 0.5;
		int us = 0;
		for(auto c : points){
			int p = c.first, q = c.second;
			double p_ = 1.0 * p, q_ = 1.0 * q;
			if(bot <= q_ && q_ <= top && lef <= p_ && p_ <= rig) us++;
		}
		ans = max(ans, us);
	}
	cout << ans << endl;

	return 0;
}