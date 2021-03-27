#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
vector<int> a[maxn];
int b[maxn];
bool judge(vector<int> &num){
	int cnt = 0, p;
	// cout << num[2] << endl;
	for(int i = 1; i < (int)num.size(); i++){
		if(num[i] > num[i-1]) cnt++, p = i;
	}
	// cout << cnt <<endl;
	if(cnt > 1) return false;
	if(cnt == 0) return true;
	// cout << p << endl;
	return num.back() >= num[0];
}
void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		vector<int> num(x);
		for(int i = 0; i < x; i++) cin >> num[i];
		if(judge(num)) cout << "Y" << endl;
		else cout << "N" << endl;
	}
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}