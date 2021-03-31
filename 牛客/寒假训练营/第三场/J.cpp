#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 1e6 + 10;
const ll mod = 1e9 + 7;
int n;
ll f[maxn];
void solve(){
	cin >> n;
	f[0] = 1; f[1] = 2; f[2] = 3;
	for(int i = 3; i <= 40; i++){
		f[i] = f[i-1] + f[i-2];
	}	
	for(int i = 41; i <= n; i++) f[i] = 1;
	for(int i = 1; i <= n; i++) cout << f[i] << " ";

	cout << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}