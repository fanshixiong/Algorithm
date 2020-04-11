//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 105 /*rem*/
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
int n;
int fl[75];

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		memset(fl, -1, sizeof(fl));
		int pl = 0;
		for (int k = 0; k <= 30; k++) {
			if ((1 << k) + k > n) {
				pl = k - 1;
				break;
			}
		}
		for (int j = 0; j <= pl; j++)
			fl[j] = 0;
		n -= (pl + 1);
		for (int j = pl; j >= 0; j--) {
			int pls = (1 << j) - 1;
			if (pls <= n) n -= pls, fl[j] = 1;
		}
		while (n) {
			fl[pl + 1] = 0;
			n--;
			pl++;
		}
		printf("Case #%d:\n", i);
		int dr = 0; // 0 : 左 1 : 右 
		for (int i = 0; i < 75; i++) {
			if (fl[i] == -1) break;
			if (fl[i] == 0) {
				if (dr == 0) printf("%d %d\n", i + 1, 1);
				else printf("%d %d\n", i + 1, i + 1);
			}
			else {
				if (dr == 0)
					for (int j = 1; j <= i + 1; j++)
						printf("%d %d\n", i + 1, j);
				else
					for (int j = i + 1; j >= 1; j--)
						printf("%d %d\n", i + 1, j);
				dr ^= 1;
			}
		}
	}
	return 0;
}
