#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n; cin >> n;
	vector<int> nums(n+1);
	for(int i=0; i<n; i++)
		cin >> nums[i];
	int i=0, j=n-1;
	while(nums[i++]);
	while(nums[j--]);
	if(((i-1)&1) || ((n-j-2)&1)) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
} 
