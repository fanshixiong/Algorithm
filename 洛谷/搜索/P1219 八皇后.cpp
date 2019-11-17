#include <iostream>
#include <vector>
using namespace std;
vector<int> queen(15);
long res = 0;
int n;
/*
void dfs(int k){
	if (k >= n){
		res++;	
		if (res <= 3){
			for (int i = 0; i < n; i++)
				cout << queen[i]+1 << " ";
			cout << endl;
		}
		return;
	}
	for (int i = 0; i < n; i++){
		queen[k]=i;
		bool b = 1;
		for (int j = 0; j < k; j++){
			if (queen[j] == queen[k] || j-queen[j] == k-queen[k] || j+queen[j] == k+queen[k]){
				b=0;
				break;
			}
		}
		if(b) dfs(k+1);
	}
} */
vector<int> right_x(50);
vector<int> left_x(50);
vector<int> cols(20);
void dfs(int k){
	if (k >= n){
		res++;
		if (res > 3)return;
		for (int i = 0; i < n; i++)
			cout << queen[i]+1 << " ";
		cout << endl;
		return;
	}
	for(int i = 0; i < n; i++){
		if (!cols[i] && !left_x[i+k] && !right_x[k-i+n+1]){
			queen[k] = i; cols[i]++; left_x[i+k]++; right_x[k-i+n+1]++;
			dfs(k+1);
			cols[i]--; left_x[i+k]--; right_x[k-i+n+1]--;
		}
	}
}
int main(){
	cin >> n;
	dfs(0);
	cout << res << endl;
	return 0;
}
