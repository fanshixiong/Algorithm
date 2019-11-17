#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, K;
	cin >>N>>K;
	vector<int> num(N+1, 0);
	vector<int> cnt(N);
	long long res = 0;
	for (int i = 1; i <= N; i++){
		cin >> num[i];
		num[i] = (num[i-1]+num[i])%K;
		res += cnt[num[i]];
		cnt[num[i]]++;
	}
	
	cout << res+cnt[0]<< endl;
	return 0;
}
