/*小蓝赛：赛亚人
贪心 
*/
#include<iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin >> n; 
	vector<int> nums(100001);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	int res = 0;
	vector<int> vis(n+1);
	for (int i = 0; i < n; i++){
		int pos = 0;
		for(int j = i; j < n; j++){
			if (!vis[j] && pos < nums[j]){
				if(pos == 0) res++;
				pos = nums[j];
				vis[j]=true;
			}
		}
	}
	cout << res << endl;
    return 0;
} 

