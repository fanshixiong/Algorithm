// 2018.12.13
//������ ������  �ʾ�(����dp)

//�ʾ֣�һЩ��ׯ����һ����ֱ�ĸ��ٹ�·���ϡ�
//������һ���������������������ٹ�·��ÿһ����ׯ�����궼��������û��������ׯ������ͬ��
//������ׯ��ľ��룬����Ϊ���ǵ�����ֵ��ľ���ֵ��
//������Ҫ��һЩ��ׯ�����ʾ֨D�D��Ȼ��������ÿһ����ׯ�����뽨���ʾ֣��ʾֱ��뱻���ڴ�ׯ������������������ڴ�ׯ������ͬ��
//ÿ����ׯ��������������Ǹ��ʾ֣�������Щ�ʾֵ�ԭ���ǣ����д�ׯ��������ʹ�õ��ʾֵľ����ܺ���С��

//���������ⲻ̫���룬���ǿ��Ա������⵽һ���˼�룬�ȿ��Ǵ�ׯi����ׯj֮��ֻ��һ���ʾֵ������
//��ô����ʾ־�һ����i��j���е㴦�� (��ʵ������ׯΪż��ʱ����λ�����������м����߻������ұߣ����յĽ������һ���ģ����Բ��ÿ�����ż��)
//��dis[i][j]��ʾi��j֮��ֻ��һ���ʾ�ʱ�ľ���ͣ��� 
//dis[i][j]=dis[i][j-1]+pos[j]-poj[(i+j)>>1]; 
//�������������Ƕ���ʾֵ������ͬ�����е���ʽ����dp[i][j]��ʾǰi����ׯ����j���ʾֵľ�����С�ͣ��� 
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



