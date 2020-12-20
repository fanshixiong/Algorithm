#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define pi pair<int, int>
#define pb push_back
const int maxn = 1e6 + 10;
set<int> G[maxn];
map<pi, int> W;

int n, m, s, t; 
int L, R;
bool dfs(int u, int fa, int x, int _){
	for(auto p : G[u]){
		int v = p, w = W[{u, v}];
		if(v == fa) continue;
		// cout << u << " " << v << endl;
		if(_) {
			if(w < L || w > x) continue;
		}
		else{
			if(w < x) continue;
		}

		if(v == t) return true;
		if(dfs(v, u, x, _)) return true;
	}
	return false;
}
void solve(){
    scanf("%d%d%d%d", &n, &m, &s, &t);

    for(int i = 0; i < m; i++){
    	int x, y, w;
    	scanf("%d%d%d", &x, &y, &w);
    	G[x].insert(y);
    	G[y].insert(x);
    	if(W.count({x, y})) W[{x, y}] = max(W[{x, y}], w);
    	else W[{x, y}] = w;

    	if(W.count({y, x})) W[{y, x}] = max(W[{y, x}], w);
    	else W[{y, x}] = w;
    }

    
    int l = 1, r = 1e9;
    while(l <= r){
    	int mid = (l+r)/2;
    	if(dfs(s, -1, mid, 0)){
    		// cout << "L::: " << l << " " << r << " " << mid << endl;
    		L = mid;
    		l = mid+1;
    	}
    	else r = mid-1;
    }
    // cout << dfs(s, -1, 2, 1);

    l = L; r = 1e9;
    while(l <= r){
    	int mid = (l+r)/2;
    	if(dfs(s, -1, mid, 1)){
    		// cout << "R::: " << l << " " << r << endl;
    		R = mid;
    		r = mid-1;
    	}
    	else l = mid+1;
    }
    cout << L << " " << R << endl;
    
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}