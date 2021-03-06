#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
void solve(){
	int n, k; cin >> n >> k;
	if(n < 6 && n / 2 == k){ cout << -1 << endl; return;}
	if(n /2 > k){
		int cnt = -1;
		for(int i = 2; i <= n; i += 2){
			cout << i << " ";
			cnt++;
			if(cnt == k) break;
		}
		for(int i = 1; i <= n; i ++){
			if((i & 1) || i > (cnt + 1) * 2) cout << i << " ";
		}
	}
	else{
		for(int i = 2; i <= n; i += 2) if(i != 6) cout << i << " ";
		cout << "6 3 1 ";
		for(int i = 5; i <= n; i += 2) cout << i << " ";
 	}
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}