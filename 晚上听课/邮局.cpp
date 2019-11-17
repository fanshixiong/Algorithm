// 2018.12.13
//周四晚 周天行  邮局(区间dp)

//邮局：一些村庄建在一条笔直的高速公路边上。
//我们用一条坐标轴来描述这条高速公路，每一个村庄的坐标都是整数，没有两个村庄坐标相同。
//两个村庄间的距离，定义为它们的坐标值差的绝对值。
//我们需要在一些村庄建立邮局――当然，并不是每一个村庄都必须建立邮局，邮局必须被建在村庄里，因此它的坐标和它所在村庄坐标相同。
//每个村庄便用离它最近的那个邮局，建立这些邮局的原则是：所有村庄到各自所使用的邮局的距离总和最小。

//分析：本题不太好想，我们可以本着特殊到一般的思想，先考虑村庄i到村庄j之间只有一个邮局的情况。
//那么这个邮局就一定在i和j的中点处。 (其实在若村庄为偶数时的中位数无论是在中间的左边还是在右边，最终的结果都是一样的，所以不用考虑奇偶数)
//令dis[i][j]表示i到j之间只有一个邮局时的距离和，则 
//dis[i][j]=dis[i][j-1]+pos[j]-poj[(i+j)>>1]; 
//下面我们来考虑多个邮局的情况，同样可有递推式：令dp[i][j]表示前i个村庄建了j个邮局的距离最小和，则 
//dp[i][k]=dp[i][k-1]+dis[j+1][i]; (0<=j<i<n) 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int inf = 0x3f3f3f3f;
int main(){
	freopen("in.txt", "r", stdin);
	int n, m;
	cin >> n;
	cin >> m;
	vector<int> nums(n);
	for (int i = 0; i < n; i++){
		cin >> nums[i];
	}
	vector<vector<int> > dist(n, vector<int> (n, 0));
	vector<vector<int> > dp(n, vector<int> (m, inf));
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			int mid = (i+j)/2;
			for (int k = i; k <= j; k++){
				dist[i][j] += fabs(nums[k]-nums[mid]);
				dist[j][i] += fabs(nums[k]-nums[mid]);
			//	cout << dist[i][j] << " " ;
			}
			//cout << endl;
		}
		dp[i][0] = dist[0][i];
	}
	for (int k = 0; k < m; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
				if (dp[i][k] > dp[j][k-1]+dist[j+1][i])
					dp[i][k] = dp[j][k-1]+dist[j+1][i];
	cout << dp[n-1][m-1] << endl;
	return 0;
}



