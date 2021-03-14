#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define pi pair<int, int>
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
ll d, B;
struct node{
	int data[4][2];
}bill[20];
ll ans;
void dfs(int p, ll curBug, ll curLive){
	ans = max(ans, curLive); 
	if(p >= d) return;
		
	dfs(p+1, curBug, curLive);
	for(int i = 0; i < 4; i++){
		ll x = curBug + bill[p].data[i][0], y = curLive + bill[p].data[i][1];
		if(x <= B) dfs(p+1, x, y);
	}
}
void solve(){
	cin >> d >> B;
	for(int i = 0; i < d; i++){
		for(int k = 0; k < 4; k++) cin >> bill[i].data[k][0] >> bill[i].data[k][1];
	}
	ans = 0;
	dfs(0, 0, 0);
	cout << ": Maximum of " << ans << " lives saved." << endl << endl;
}
int main(){
    IOS; int t; cin >> t;
    int x = 0;
    while(x ++ < t){
    	cout << "Budget #" << x;
        solve();
    }
    return 0;
}
/*
3
2 2000
100 1 200 2 300 3 1900 1000
10 5 50 100 100 1000 250 1100
3 100
5 1 25 2 35 3 50 4
10 100 40 200 70 300 100 500
200 10000 300 20000 400 30000 500 40000
1 10
100 2 200 3 300 5 400 6
*/