#include <iostream>
#include <vector>
using namespace std;

void LCSLength (int n1, int n2, string s1, string s2, vector<vector<int> > &dp, vector<vector<int> > &trace)
{
	int i, j;
	for(i = 1; i <= n1; i++) dp[i][0] = 0;
	for(i = 1; i <= n2; i++) dp[0][i] = 0;
	
	for(i = 1; i <= n1; i++)
		for(j = 1; j <= n2; j++)
		{	
			if (s1[i] == s2[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				trace[i][j] = 1;
			}
			else if (dp[i-1][j] >= dp[i][j-1]) {
				dp[i][j] = dp[i-1][j];
				trace[i][j] = 2;
			}	
			else {
				dp[i][j] = dp[i][j-1];
				trace[i][j] = 3;
			}
		}
}
void TraceBack (int i, int j, string s1, vector<vector<int> > &trace)       //i j 代表 两个字符串的长度 
{
	if (i == 0 || j == 0) return;
	if (trace[i][j] == 1) {
		TraceBack(i-1, j-1, s1, trace);
		cout << s1[i-1] << " ";
		
	}
	else if(trace[i][j] == 2)
		TraceBack(i-1, j, s1, trace);
	else
		TraceBack(i, j-1, s1, trace);
}
int main ()
{
	string s1 = "faccc";
	string s2 = "faccc";
	vector<vector<int> > dp(s1.length()+1 , vector<int> (s2.length()+1 ));
	vector<vector<int> > trace(s1.length()+1 , vector<int> (s2.length()+1 ));
	LCSLength (s1.length(), s2.length(), s1, s2, dp, trace);
	TraceBack(s1.length() , s2.length(), s1, trace);
	return 0;
}
