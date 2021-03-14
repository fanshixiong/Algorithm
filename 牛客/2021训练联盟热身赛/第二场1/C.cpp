#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
bool check(int x){
	vector<int> num;
	while(x){
		num.push_back(x % 10);
		x /= 10;
	}
	int n = num.size();
	int i = 0, j = n-1;
	while(i <= j){
		if(num[i++] != num[j--]) return false;
	}
	return true;
}
void solve(){
	int x; cin >> x;
	cout << "Input cost: " << x << endl;

	int tips = (x * 0.2);
	if(tips * 5 != x) tips++;
	x += tips;

	for(int i = x; i <= 20010; i++){
		if(check(i)){
			cout << tips + (i-x) << " " << i << endl << endl;
			return;
		}
	}
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}