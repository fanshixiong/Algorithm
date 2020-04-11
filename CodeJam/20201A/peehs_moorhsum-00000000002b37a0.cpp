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
int a[maxn][maxn];
char inp[maxn][maxn];
char fr[maxn];
char ed[maxn];
char md[maxn * maxn];
int cnt = 0;
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		fr[0] = ed[0] = '\0';
		cnt = 0;
		bool fl = 1;
		for (int j = 1; j <= n; j++) {
			scanf("%s", inp[j]);
			int f[2];
			int le = strlen(inp[j]);
			for (int k = 0; k <= le; k++) 
				if (k == le || inp[j][k] == '*') {
					f[0] = k;
					int l = strlen(fr);
					for (int s = 0; s < min(k, l); s++)
						if (fr[s] != inp[j][s]) fl = 0;
					if (k > l) {
						for (int m = 0; m < k; m++)
							fr[m] = inp[j][m];
						fr[k] = '\0';
					}
					break;
				}
			for (int k = le - 1; k >= -1; k--) {
				if (k == -1 || inp[j][k] == '*') {
					f[1] = k;
					int l = strlen(ed);
					int nl = le - k - 1;
					for (int s = 0; s < min(l, nl); s++)
						if (ed[l - s - 1] != inp[j][le - 1 - s]) fl = 0;
					if (nl > l) {
						for (int s = 0; s < nl; s++)
							ed[nl - 1 - s] = inp[j][le - 1 - s];
						ed[nl] = '\0';
					}
					break;
				}
			}
			for (int k = f[0]; k <= f[1]; k++)
				if (inp[j][k] != '*') md[cnt++] = inp[j][k]; 
		} 
		md[cnt++] = '\0';
		printf("Case #%d: ", i);
		if (fl) {
			printf("%s", fr);
			printf("%s", md);
			printf("%s", ed);
			printf("\n");
		}
		else {
			printf("*\n");
		}
	}
	return 0;
}
