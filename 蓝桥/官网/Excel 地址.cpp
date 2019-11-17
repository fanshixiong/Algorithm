#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	long long n; cin >> n;
	vector<int> num;
	long long x, y;
	while(n){
		y=n%26;
		if(y==0)
			y=26;
		n=(n-y)/26;
		num.push_back(y);  
	}
	for(int i=num.size()-1; i>=0; i--){
		cout << (char)(num[i]+64);
	}
	cout <<endl;
	return 0;
} 
