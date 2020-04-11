//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
const int N = 1000005;
set<pi> r[2][N];
int c[2];
int w[N];
int cid(int x, int y) {
	return x * c[1] + y;
}
#define iter set<pi>::iterator
vi ne(int x, int y) {
	int u[2] = {x, y};
	vi fn;
	for (int k = 0; k < 2; k++) {
		iter t = r[k][u[k]].lower_bound(mp(u[k ^ 1], 1e9 + 1));
		iter s = t;
		s--;
		if ((*s).fi == u[k ^ 1]) s--;
		if ((*t).se != -1) fn.pb((*t).se);
		if ((*s).se != -1) fn.pb((*s).se);
	}
	return fn;
}
pi caln(int x, int y) {
	vi gg = ne(x, y);
	int fr = 0;
	for (auto v : gg) fr += w[v];
	return mp(fr, gg.size());
}
queue<int> ers;
vi tbc;
vi er;
int fl[N]; // 是否被抹去 
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		ll s = 0;
		scanf("%d%d", &c[0], &c[1]);
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < c[j]; k++) {
				r[j][k].clear();
				r[j][k].insert(mp(-1, -1));
				r[j][k].insert(mp(1e9, -1));
			}
		tbc.resize(c[0] * c[1]);
		for (int x = 0; x < c[0]; x++)
			for (int y = 0; y < c[1]; y++) {
				int nw;
				scanf("%d", &nw);
				s += nw;
				int id = cid(x, y);
				tbc[id] = id;
				w[id] = nw;
				fl[id] = 0;
				int u[2] = {x, y};
				for (int j = 0; j < 2; j++)
					r[j][u[j]].insert(mp(u[j ^ 1], id));
			}
		ll ans = 0;
		while (1) {
			er.clear();
			vector<int>().swap(er); 
			sort(tbc.begin(), tbc.end());
			ans += s;
			for (int i = 0; i < tbc.size(); i++) {
				if (i != 0 && tbc[i] == tbc[i - 1]) continue;
				int id = tbc[i];
				if (fl[id]) continue;
				pi cu = caln(id / c[1], id % c[1]);
			//	cout << i << ' ' << id << ' ' << cu.fi << ' ' << cu.se << endl;
				if (cu.se * w[id] < cu.fi) er.pb(id);
			}
			if (!er.size()) break;
			tbc.clear();
			vector<int>().swap(tbc);
			for (auto v : er) {
				s -= w[v];
				fl[v] = 1;
			//	cout << "ERASE" << v << endl;
				int u[2] = {v / c[1], v % c[1]};
				for (int j = 0; j < 2; j++)
					r[j][u[j]].erase(mp(u[j ^ 1], v));
				vi cr = ne(u[0], u[1]);
			//	cout << "NEI" << cr.size() << endl;
				for (auto g : cr) tbc.pb(g);
			}
		}
		printf("Case #%d: %lld\n", i, ans); 
	}
	return 0;
}
 