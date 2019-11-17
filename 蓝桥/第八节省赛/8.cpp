#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
int INF = 1000;
using namespace std;
int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a%b);
}
int main(){
	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++){
		cin >> num[i];
	}
	int g = num[0];
	for (int i = 1; i < n; i++){
		g = gcd(g, num[i]);
	}
	if (g != 1){
		cout << "INF" << endl;
		return 0;
	}
	int res = 0;
	vector<int> dp(10001);
	dp[0] = 1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j + num[i]< 10001; j++){
			if (dp[j])
				dp[j+num[i]]++;
		}
	}
	for (int i = 1; i < 10001; i++){
		if (!dp[i])
			res++;
	}
	cout << res << endl;
	return 0;
}
