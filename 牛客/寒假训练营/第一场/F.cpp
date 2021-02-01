#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
void solve(){
	int n;
	cin >> n;
	char nn[110], nm[110];
	for(int i = 0; i < n; i++) cin >> nn[i];
	for(int i = 0; i < n; i++) cin >> nm[i];

	int cnt = 0;
	for(int i = 0; i < n; i++) if(nn[i] == nm[i]) cnt++;

	cout << cnt + n << " " << 0 << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}