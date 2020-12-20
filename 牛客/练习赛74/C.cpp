#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define pi pair<int, int>
#define pb push_back
const int maxn = 1e6 + 10;
vector<pi> G[maxn];


int n, m, s, t; 
bool dfs(int u, int fa, int x, int _){
	for(auto p : G[u]){
		int v = p.first, w = p.second;
		if(v == fa) continue;
		// cout << u << " " << v << endl;
		if(_) {
			if(w > x) return false;
		}
		else{
			if(w < x) return false;
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
    	G[x].pb({y, w});
    	G[y].pb({x, w});
    }

    // cout << dfs(s, -1, 3, 0);
    
    int L;
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

    l = L; r = 1e9;
    int R;
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