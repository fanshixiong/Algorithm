#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 5e5 + 10;
const ll mod = 1e9 + 7;
int n;
int f[maxn], sz[maxn];
int a[550][550];
string s[550];
int d[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};
ll qsm(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res % mod;
}
void init(){
	for(int i = 0; i <= n * n; i++) f[i] = i, sz[i] = 1;
}
int Find(int x){
	if(x == f[x]) return x;
	return f[x] = Find(f[x]);
}
void Union(int x, int y){
	x = Find(x), y = Find(y);
	if(x == y) return;
	f[x] = y;
	sz[y] += sz[x];
}
void solve(){
	cin >> n;
	init();
	for(int i = 0; i < n; i++){
		cin >> s[i];
		for(int j = 0; j < n; j++){
			char c = s[i][j];
			if(c == '0') continue;
			if(j > 0 && s[i][j-1] == '1') Union(i * n + j, i * n + j - 1); 
			if(i > 0 && s[i-1][j] == '1') Union(i * n + j, (i-1) * n + j); 
			if(i < n-1 && s[i+1][j] == '1') Union(i * n + j, (i+1) * n + j); 
			if(j < n-1 && s[i][j+1] == '1') Union(i * n + j, i * n + j + 1); 
		}
	}

	int cnt = 0;
	ll ans = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(f[i * n + j] == i * n + j && s[i][j] == '1') cnt++, ans = ans * sz[i *n + j] % mod;
		}
	}
	for(int i = 1; i <= cnt; i++) ans = ans * i % mod;


	int k; cin >> k;
	for(int i = 0; i < k; i++){
		int x, y; cin >> x >> y;
		if(s[x][y] == '1'){
			cout << ans << endl;
			continue;
		}
		s[x][y] = '1';
		cnt ++;
		ans = ans * cnt % mod;
		for(int i = 0; i < 4; i++){
			int dx = x + d[i][0], dy = y + d[i][1];
			if(dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
			if(s[dx][dy] == '1'){
				int f1 = Find(dx * n + dy), f2 = Find(x * n + y);
				if(f1 != f2){
					ans = ans * qsm(cnt, mod - 2) % mod;
					ans = ans * qsm(sz[f1], mod - 2) % mod;
					ans = ans * qsm(sz[f2], mod - 2) % mod;
					ans = ans * (sz[f1] + sz[f2]) % mod;
					cnt--;
					Union(f1, f2);
				}
			}
		}
		cout << ans << endl;
	}
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}