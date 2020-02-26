#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 55, M = 2e4 + 5;
int n, m, k, sum[N][M], lmax[N][M], rmax[N][M], dp[N][M];
int get(int i, int s, int e) {
	return sum[i][e] - sum[i][s - 1];
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &sum[i][j]);
			sum[i][j] += sum[i][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m - k + 1; j++) {
			int ksum = get(i, j, j + k - 1) + get(i + 1, j, j + k - 1);
			if (i == 1) {
				dp[i][j] = ksum;
				continue;
			}printf("%d ", ksum); 
            
			for (int x = max(1, j - k + 1); x <= min(j + k - 1, m - k + 1); x++) {
				dp[i][j] = max(dp[i][j], dp[i - 1][x] + ksum - get(i, max(x, j), min(x + k - 1, j + k - 1)));				
			} 	
			
			if (j > k) 
                dp[i][j] = max(dp[i][j], lmax[i - 1][j - k] + ksum); 
			if (j + k <= m) 
                dp[i][j] = max(dp[i][j], rmax[i - 1][j + k] + ksum);
			
		}
		//更新lmax 和 rmax
		for (int j = 1; j <= m - k + 1; j++) {
			lmax[i][j] = max(lmax[i][j - 1], dp[i][j]);
			
		} 
		for (int j = m - k + 1; j >= 1; j--) {
			rmax[i][j] = max(rmax[i][j + 1], dp[i][j]);
		}
		printf("\n");
	}
	int ans = 0;
	for (int j = 1; j <= m - k + 1; j++){
        ans = max(ans, dp[n][j]);
    }
    printf("%d", ans);
    return 0;
} 
