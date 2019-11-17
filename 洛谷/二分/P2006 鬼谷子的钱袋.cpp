#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	int m=n;
	vector<int> ans;
	while(m){
		ans.push_back((m+1)/2);
		m/=2;
	}
	cout << ans.size() << endl; 
	for(int i=ans.size()-1; i>=0; i--)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
} 
