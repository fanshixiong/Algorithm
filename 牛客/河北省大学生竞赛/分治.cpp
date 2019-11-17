#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int cost[101];
int dp[101][101];
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> cost[i];
        }
        memset(dp, 0, sizeof(dp));
        for(int len=1; len<n; len++){
            for(int i=1; i<=n-len; i++){
                int j=len+i;
                dp[i][j]=0x3f3f3f3f;
                for(int k=i; k<=j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k-1]+dp[k+1][j]+cost[k]*len);
                }
            }
        }
        cout << dp[1][n] << endl;
    }
    return 0;
}
