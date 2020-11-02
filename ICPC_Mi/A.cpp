#include <bits/stdc++.h>

using namespace std;
const int maxn = 3e5 + 10;
int a[maxn], dp[maxn];
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",&a[i]);
    sort(a, a + n);

    memset(dp, 0, sizeof dp);
    int max = 0;
    for (int i = 0; i < n; ++i) {
        int limit = a[i] / 2;
        int maxcount = 1;
        for (int j = 0; a[j] <= limit; ++j) {
            if (a[i] % a[j] == 0) {
                if (dp[j] + 1 > maxcount) {
                    maxcount = dp[j] + 1;
                }
            }
        }
        dp[i] = maxcount;
    }
    for(int i = 0; i < n; i++) if(dp[i]>max) max=dp[i]; 
    printf("%d ", max);
 
}