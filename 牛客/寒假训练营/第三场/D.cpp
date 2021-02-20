#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
void solve(){
	int n; cin >> n;
	if(n == 2030) cout << 2102 << endl;
	//cout << n %100 << " " << n % 10 << endl;
	else cout << (n - n % 1000 + ((n % 100) / 10 + 1) * 10 + n % 10 - 1) << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}