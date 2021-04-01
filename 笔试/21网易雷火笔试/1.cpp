#include<bits/stdc++.h>
using namespace std;
int main(){
	map<int, vector<int> > p;
	for(int i = 0; i < 27; i++){
		int x, y; cin >> x >> y;
		if(x == 15 || x == 16) continue;
        if(x == 14) p[y].push_back(1);
		p[y].push_back(x);
	}
	/*
	for(int i = 1; i <= 4; i++){
		sort(p[i].begin(), p[i].end());
	}
	*/
	int ans = 0;
	for(int i = 1; i <= 4; i++){
		if(p[i].size() < 5) continue;
		vector<int> vis(20, 0);
		for(auto c : p[i]) vis[c]++;
		for(int j = 1; j <= 11; j++){
			bool flag = 1;
			int us = 0;
			for(int k = 0; k < 5; k++) {
				if(!vis[j+k]){
					flag = 0;
					break;
				}
				us = max(us, vis[j+k]);
			}
			if(flag) ans += us;
		}
		// cout << i << " dd " << ans << endl;
	}
	cout << ans << endl;
	return 0;
}