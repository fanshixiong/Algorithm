#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int res;
		cin >> res;
		for(int i=1; i<n; i++){
			int x;
			cin >> x;
			res ^= x;
		}
		if(res || n&1){
			cout << "lolanv" << endl;
		}
		else{
			cout << "Wind" << endl;
		}
	}
	return 0;
} 
