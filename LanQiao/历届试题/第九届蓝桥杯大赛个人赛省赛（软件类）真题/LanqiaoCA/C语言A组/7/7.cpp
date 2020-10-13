#include<bits/stdc++.h>

using namespace std;
 
int a[200][200][200];
 
int main() {
	freopen("7.txt", "r", stdin);
	
	int A, B, C, m;
	scanf("%d%d%d%d", &A, &B, &C, &m);
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < B; j++) {
			for (int k = 0; k < C; k++)
				scanf("%d", &a[i][j][k]);
		}
	}
	int lat, rat, lbt, rbt, lct, rct, ht;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d%d%d%d%d", &lat, &rat, &lbt, &rbt, &lct, &rct, &ht);
		for (int j = lat - 1; j <= rat - 1; j++) {
			for (int k = lbt - 1; k <= rbt - 1; k++) {
				for (int p = lct - 1; p <= rct - 1; p++) {
					a[j][k][p] -= ht;
					if (a[j][k][p] < 0) {
						printf("%d\n", i);
						exit(0);
					}
				}
			}
		}
	}
	return 0;
}
