#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n; cin >> n;
	vector<int> num(n+2);
	for(int i=1; i<=n; i++)
		cin>> num[i];
	vector<int> dp1(n+1, 1), dp2(n+1, 1); //不是0  因为至少有一个人 
	for(int i=1; i<=n; i++){
		for(int j=1; j<i; j++){
			if(num[i] > num[j])
				dp1[i]=max(dp1[i], dp1[j]+1);
		}
	}
	for(int i=n; i>=1; i--){
		for(int j=n; j>i; j--){
			if(num[j]<num[i])
				dp2[i]=max(dp2[i], dp2[j]+1);
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		ans=max(ans, dp1[i]+dp2[i]-1);
	}
	cout << n-ans << endl;
	return 0;
} 
