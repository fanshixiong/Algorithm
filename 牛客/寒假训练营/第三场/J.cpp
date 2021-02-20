#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 1e6 + 10;
const ll mod = 1e9 + 7;
int n;
int a[maxn];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];

	int odds = 0, evens = 0;
	for(int i = 0; i < n; i++){
		if(a[i] & 1) odds ++;
		else evens ++;
	}
	if(evens <= odds){
		cout << "NiuMei" << endl;
		return;
	} 
	if(evens == 0) odds --;
	while(odds > 0 && odds + evens > 1){
		odds -= 2;
	}
	if(odds) cout << "Niuniu" << endl;
	else cout << "NiuMei" << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}