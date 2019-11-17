// ×Ö·û´®µÄ±à¼­¾àÀë 
//dp[i][j] = { min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1 , str1[i-1] != str2[j-1]; //·Ö±ð´ú±íÉ¾³ý£¬Ìí¼Ó£¬Ìæ»» 
//             dp[i-1][j-1], str1[i-1] == str2[j-1]				                      }		 
	
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	string str1, str2;
	cin >> str1 >> str2; 
	int n = str2.size();
	int m = str1.size();
	vector<vector<int> > dp(m+1, vector<int>(n+1));
	for (int i = 0; i <= m; i++)
		dp[i][0] = i;
	for (int i = 0; i <= n; i++)
		dp[0][i] = i;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			if (str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else 
				dp[i][j] = min (dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
		}
	}
	cout << dp[m][n]; 
	system("PAUSE");
	return 0;
}
