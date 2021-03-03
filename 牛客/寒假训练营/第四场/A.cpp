#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
void solve(){
	int n, m;
	cin >> n >> m;
	int x; 
	string s;
	vector<int> cnt(m + 1, 0), sum(m + 1, 0);
	vector<bool> ans(m + 1, false);
	for(int i = 0; i < n; i++){
		cin >> x >> s;
		if(s[0] == 'A') cnt[x]++;
		sum[x]++;
		if(cnt[x] * 2 < sum[x]) ans[x] = true;
	}
	bool flg = false;
	for(int i = 1; i <= m; i++) if(!ans[i]) cout << i << " ", flg = true;
	if(!flg) cout << -1;
	cout << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}