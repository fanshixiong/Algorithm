/*
#include<iostream>
#include <vector>
using namespace std;
int main(){
	int res = 0;
	string s;
	cin >> s;
	int head = 0, tail = s.size()-1;
	while(head <= tail){
		if (s[head] == s[tail]){
			head++;tail--;
		}
		else{
			int h1 = head, t1 = tail;
			while (s[h1] != s[tail])
				h1++;
			while (s[t1] != s[head])
				t1--;
			if (tail - t1 > h1 - head){
				res += h1-head;
				head = h1+1;
				tail--;
			}
			else{
				res += tail-t1;
				tail = t1-1;
				head++;
			}
		}
	}
	cout << res << endl;
	return 0;
} 
*/
/*
动态规划 
将字符串逆序然后求最长公共子串，相减即为所求
*/
#include<iostream>
#include <vector>
using namespace std;
int main(){
	string s;
	cin >> s;
	int res = 0;
	int n = s.size();
	vector<vector<int> > dp(n+1, vector<int>(n+1));
	string ss;
	int k = 0;
	for (int i = n-1; i >= 0; i--)
		ss[k++] = s[i];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if(s[i-1]==ss[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout << n-dp[n][n] << endl;
	return 0; 
} 

