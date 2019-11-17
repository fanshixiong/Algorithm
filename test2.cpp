/*小蓝赛分组问题 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int INF = 0x3f3f3f3f; 

int main(){
	int n, m; cin >> n>> m;
	if (m <= 0 || n <= 0){
		cout << 0 << endl;
		return 0;
	}
	vector<int> nums(n+1);
	vector<int> sum(n+1);                                //前i个元素的和 
	for (int i = 1; i <= n; i++){
		cin >> nums[i];
		sum[i] = sum[i-1] + nums[i];
	}
	deque<int> q;
	q.push_back(0);
	long long res = 0;
	for (int i = 1; i <= n; i++){
		while (!q.empty() && sum[i] <= sum[q.back()]){
			q.pop_back();
		}
		while (!q.empty() && (q.back()-q.front() >= m)){                 //i-front 和 >= 错误之处 
			q.pop_front();
		}
		res = max(res, (long long)sum[i]-sum[q.front()]); 
		q.push_back(i);
	}
	cout << res << endl;
	return 0;
}
