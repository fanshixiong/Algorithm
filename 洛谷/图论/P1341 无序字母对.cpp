#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<vector<int> > G(1005, vector<int>(1006));
vector<char	> res(1005);
vector<int> num(1005);               //求入度 
int n,  ans = 0;
void dfs(int k){
	for(int i = 0; i <= 150; i++){           //z不超过150 
		if (G[k][i]){
			G[k][i]=G[i][k]=0;
			dfs(i);
		}
	}
	res[++ans]=k;
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		string s;
		cin >> s;
		G[s[0]][s[1]] = G[s[1]][s[0]] = 1;
		//cout << G[s[0]][s[1]] <<" " << G[s[1]][s[0]] << endl;
		num[s[0]]++; num[s[1]]++;
	}
	int cnt = 0, beg = 0;                 //度数为奇数的个数  起点 
	for (int i=0; i<=150; i++){
		if(num[i]&1){
			cnt++;
			if(!beg)
				beg=i;
		}
	}
	if(!beg){
		for (int i = 0; i<=150; i++){
			if(num[i]){
				beg=i;
				break;
			}
		}
	}
	if(cnt && cnt!=2){
		cout << "No Solution";
		return 0;
	}
	dfs(beg);
	if(ans < n+1){
		cout << "No Solution";
		return 0;
	}
	for (int i = ans; i>= 1; i--){
		printf("%c", res[i]);
	}
	cout << endl;
	return 0;
} 
