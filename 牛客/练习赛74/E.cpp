#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1023694381;

vector<pi> G[510];
ll dist[510][510];
int a[510];

ll qpow(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}

int n, m, K;
void solve(){
	cin >> n >> m >> K;
	for(int i = 1; i <= n; i++) cin >> a[i];

	memset(dist, 0x3f, sizeof dist);
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		dist[u][v] = dist[v][u] = w;
	}

	for(int i = 1; i <= n; i++) dist[i][i] = 0;

	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(dist[i][j] > dist[i][k] + dist[k][j]) 
					dist[i][j] = dist[i][k] + dist[k][j];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j<=n; j++){
			cout << dist[i][j] << " ";
		}
		cout <<endl;
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){

		if(a[i] == 1) {
			ans = (ans + 1) % mod;
			continue;
		}
		ll p = 0, cnt = 0, sums = 0;
		for(int u = 1; u <= n; u++){
			for(int v = 1; v <= n; v++){
				if(v == u) continue;
				sums++;
				if(dist[u][v] == dist[u][i] + dist[i][v]) cnt++;
			}
		}

		cout << sums << " " <<cnt <<endl;
		p =  (sums-cnt) * qpow(sums, mod-2) % mod;

		ans = (ans + 1ll + mod - qpow(p, K)) % mod;
		cout << p << " " << ans << endl;
	}
	cout << ans << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}