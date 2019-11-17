#include"Test.h"
int value(int i, int j)
{
	int ans = 0;
	int k = min(i, j);
	k = min(n + 1 - i, k);
	k = min(n + 1 - j, k);
	int kk = k;
	while (--k)
	{
		ans += (n - (k - 1) * 2 - 1) * 4;
	}
	k = kk;
	int side = n - (k - 1) * 2;
	if (i >= j)
	{
		ans = ans + (side - (i - k)) + (side - (j - k)) - 1;
	}
	else
	{
		ans = ans + (i - k) + (j - k) + 1 + (side - 1) * 2;
	}
	int sum = 0;
	while (ans)
	{
		sum += ans % 10;
		ans /= 10;
	}
	return sum;
}

void solve() {
	cout << "sdddd" << endl;
	memset(num, 0, (n + 1) * (n + 1));
	vector<int> map[10010];
	for (int i = 0; i <= n; i++) map[0].push_back(0);
	for (int i = 0; i < m; i++) {
		int x1, x2;
		cin >> x1 >> x2;
		num[x1][x2] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (num[i][j])
				num[i][j] = value(i, j);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		map[i].push_back(0);
		for (int j = 1; j <= n; j++)
		{
			map[i].push_back(map[i][j - 1] + map[i - 1][j] + num[i][j] - map[i - 1][j - 1]);
		}
	}
	int x1, y1, x2, y2;
	while (p--)
	{
		cin >> x1 >> x2 >> y1 >> y2;
		int ans = map[x2][y2] - map[x2][y1 - 1] - map[x1 - 1][y2] + map[x1 - 1][y1 - 1];
		printf("%d\n", ans);
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> p;
		solve();
	}
	return 0;
}