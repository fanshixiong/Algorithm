#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 505, P = 1023694381;

int n, m, K, a[N], ans;

LL d[N][N];

int inline power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
        b >>= 1;
    }
    return res;
}


int main() {
    memset(d, 0x3f, sizeof d);
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) scanf("%d", a + i), d[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        d[u][v] = d[v][u] = min(d[u][v], (LL)w);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            (ans += 1) %= P;
            continue;
        }
        int s = 0, cur = 0;
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (u == v) continue;
                s++;
                if (d[u][v] == d[u][i] + d[i][v]) cur++;
            }
        }
        cout << s <<" " << cur << endl;
        int p = (LL)(s - cur) * power(s, P - 2) % P;
        ans = (ans + 1ll + P - power(p, K)) % P;
        cout << p << " " << ans<< endl;
    }
    printf("%d\n", ans);
}