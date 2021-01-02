#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
	string s; cin >> s;
	int ans = 0, n = s.size();
	if(n < 8){
		cout << 0 << endl;
		return;
	}
	string target = "NowCoder";

	int pre = -1;
	for(int i = 0; i < n-7; i++){
		string str = s.substr(i, 8);
		if(str == target){
			ans += (i-pre) * (n-(i+8)+1);
			cout << i << " " << (i-pre) * (n-(i+8)+1) << " " << ans << endl;
			pre = i;
		}
		//cout << i << " ";
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