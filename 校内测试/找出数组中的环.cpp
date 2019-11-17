//蓝桥杯{A[i], A[A[i]], A[A[A[i]]]...} 的最大输的范围 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> parents;
int Find(int x){
	if (x == parents[x])
		return x;
	else return parents[x] = Find(parents[x]);
} 
bool Union(int x, int y){
	x = parents[x];
	y = parents[y];
	if (x == y)
		return true;
	else{
		parents[y] = x;
		return false;
	}
	 
}
int main(){
	int n;
	cin >>n;
	vector<int> nums(n);
	parents.resize(n);
	vector<bool> vis(n);
	for (int i = 0; i < n; i++){
		cin >> nums[i];
		parents[i] = i;
	}
	int res = n;
	for (int i = 0; i < n; i++){
		bool flag = Union(i, nums[i]);
		if (!flag)
			res--;
	}
	cout << n-res;
	
	return 0;
}
