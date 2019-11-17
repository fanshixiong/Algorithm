#include <iostream>
#include <vector>
#include <map>
using namespace std;
long long res = 0;
void dfs(int k, int sum){
	if (sum > 13)	return;
	if (k == 14){
		if (sum == 13){
			res++;
		}
		return;
	}
	for (int i = 0; i <= 4; i++){
		dfs(k+1, sum+i);
	}
}
int main(){
	dfs(1, 0);
	cout <<res << endl;
	return 0;
}
