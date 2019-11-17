// 比赛中我用的是并查集，思考思考怎么做 


#include <bits/stdc++.h>
using namespace std;

int main(){
//	std::ios::sync_with_stdio(false);
//	freopen ("in.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i =  0; i < n; i++){
		cin >> nums[i];
	}
	vector<int> tmp(nums);
	sort(tmp.begin(), tmp.end());
	map<int, int> mmp;
	for(int i = 0; i < tmp.size(); i++){
		mmp[tmp[i]] = i;
	}
	int res = 0;
	vector<bool> visited(tmp.size(), false);
	for(int i = 0; i < tmp.size(); i++){
		if (!visited[i]){
			int j = i;
			while (!visited[j]){
				visited[j] = true;
				j = mmp[nums[j]];
			}
			res++;
		}
	}
	cout << nums.size() - res ;
	return 0;
} 



