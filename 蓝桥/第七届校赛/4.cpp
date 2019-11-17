#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
vector<int> num(14);
vector<int> vis(8);
void dfs(int step){
	if (step == 14){
		for (int i = 0; i < 14; i++){
			cout << num[i];
		}
		cout << endl;
		return;
	}
	if (!num[step]){
		for (int i = 1; i < 7; i++){
			if (!vis[i] && !num[step+i+1]){
				vis[i]++; num[step] = i; num[step+i+1] = i;
				dfs(step+1);
				vis[i]--; num[step] = 0; num[step+i+1] = 0;
			}
		}
	}
	else
		dfs(step+1);
	return;
}
int main(){
	num[0] = 7; num[1] = 4; num[6] =4 ; num[8] = 7;
	vis[7]++; vis[4]++;
	dfs(2);
	return 0;
} 
