#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
void solve(){
	string s; cin >> s;
	string ans = "";
	bool flag = false;
	for(auto c : s){
		if(flag || c == 't' || c == 'j' || c - 'a' < 10){
			ans += c;
			continue;
		}
		flag = true;
		int x = c - 'a' + 1;
		// cout << x << endl;
		ans += (x / 10 - 1 + 'a');
		ans += (x % 10 - 1 + 'a');
	}

	if(!flag){
		bool f2 = false;
		ans = "";
		for(int i = 0; i < (int)s.size(); i++){
			if(i == (int)s.size()-1) {
				ans += s[i];
				break;
			}
			
			int x = ((s[i]-'a'+1)*10 + (s[i+1]-'a'+1));
			//cout << x << endl;
			if(f2 || x > 26 || s[i+1] == 'j' || s[i+1] == 't') {
				ans += s[i];
				continue;
			}
			//cout << (char)(11 + 'a') << " " << ('i' - 'a' + 1) << endl;
			f2 = true;
			ans += (x + 'a'-1);
			i++;
		}
		if(!f2) cout << -1 << endl;
		else cout << ans << endl;
		return;
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