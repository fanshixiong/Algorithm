#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
ll quick_pow(ll x,ll n){
	ll res = 1;
	while(n > 0){
		if(n & 1)	res = res * x;
		x = x * x;
		n >>= 1;//相当于n=n/2.详情请参考位移运算符。
	}
	return res;
} 
void solve(){
    // int n; cin >> n;
    for (int i = 1; i < 20; i++){
        cout << i << " " << quick_pow(1ll*2, 1ll*i) << endl;
    }
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}