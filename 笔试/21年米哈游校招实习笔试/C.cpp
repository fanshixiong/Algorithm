#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
int n, w;
int x[maxn], y[maxn];
bool check(int p){
	vector<int> num;
	for(int i = 1; i <= n; i++){
		if(x[i] > p) num.push_back(x[i]);
		else if(y[i] < p) num.push_back(y[i]);
		else num.push_back(p);
	}
	sort(num.begin(), num.end());
	int sums = 0;
	for(auto c : num) sums += c;
	if(sums > w || num[num.size() / 2] != p) return false;
	return true;
}
void solve(){
	cin >> n >> w;
	for(int i = 1; i <= n; i++) cin >> x[i] >>y[i];

	int l = 0, r = w;
	int ans = 0;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}
		else r = mid-1;
	}
	cout << ans << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}