#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
void solve(){
	int n; cin >> n;
	int f = 0;
	if(n & 1){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << f;
				f = !f;
			}
			cout << endl;
		}
	}
	else{
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << f;
				f = !f;
			}
			f = !f;
			cout << endl;
		}
	}
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}