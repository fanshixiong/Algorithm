#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main(){
	int n; cin >> n;
	vector<int> nums(n);
	long long res=0;
	for(int i=0; i<n; i++){
		cin >> nums[i];
		res ^= nums[i];
	}
	if(res == 0){
		cout << "lose" << endl;
		return 0;
	}
	for(int i=0; i<n; i++){
		if((res^nums[i]) < nums[i]){
			cout << (nums[i] - (res^nums[i]))<< " " << (i+1) << endl;
			nums[i] ^= res;
			break;
		}
	}
	for(int i=0; i<n; i++)
		cout << nums[i] << " ";
	return 0;
} 
