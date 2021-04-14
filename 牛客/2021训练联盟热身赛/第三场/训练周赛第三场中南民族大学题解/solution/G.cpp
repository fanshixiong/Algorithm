#include <bits/stdc++.h>

using namespace std;

int n, a[105];
double p[105], d[105][105];
//d[i][j]代表提交了i篇正确j篇的概率

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n, greater<int>());
    for (int i = 1; i <= n; i++) p[i] = 1.0 * a[i] / 100;
    d[0][0] = 1.0;
    for (int i = 1; i <= n; i++) {
        d[i][0] = d[i - 1][0] * (1.0 - p[i]);
        for (int j = 1; j < i; j++)
            d[i][j] = d[i - 1][j] * (1.0 - p[i]) + d[i - 1][j - 1] * p[i];
        d[i][i] = d[i - 1][i - 1] * p[i];
    }
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        double res = 0;
        for (int j = 1; j <= i; j++)
            res += pow(j, 1.0 * j / i) * d[i][j];
        ans = max(ans, res);
    }
    printf("%.10lf\n", ans);
    return 0;
}