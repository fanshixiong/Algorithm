#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int N, K; cin >> N >> K;
	vector<int> H(N);
	vector<int> W(N);
	int max_b = 0;
	for (int i = 0; i < N; i++){
		cin >> H[i] >> W[i];
		int x = min (H[i], W[i]);
		max_b = max(max_b, x);
	}
	int res;
	int min_b = 1;
	while (min_b <= max_b){
		int x = (min_b + max_b)/2;
		int ans = 0;
		for (int i = 0; i < N; i++){
			ans += (H[i]/x) * (W[i]/x);
		}
		if (ans >= K){
			min_b = x+1;
			res = x;
		}
		else
			max_b = x-1;
	}
	cout << res << endl;
	return 0;
}
