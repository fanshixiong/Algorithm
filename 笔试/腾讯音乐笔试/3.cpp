#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e2 + 10;
int dp[maxn];
string s;
int n;
int solve() {
	cin >> s;
	n = s.size();
	for(int i = 0; i < n; i++){
		unordered_map<char, int> l, r;
		for(int j = i - 1; j >= 0; j--) l[s[j]]++;
		for(int j = i + 1; j < n; j++) r[s[j]]++;
		int tmp = 0;
		int m1 = min(l['1'], r['1']);
		int m2 = min(l['2'], r['2']);
		int m3 = min(l['3'], r['3']);
		int m4 = min(l['4'], r['4']);
		tmp = max(l['1']-m1, r['1']-m1) * 200 
	}
}

int main(){
	int t; t = 1;
	while(t--){
		solve();
	}
	return 0;
}