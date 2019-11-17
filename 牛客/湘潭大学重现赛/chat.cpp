#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
//全局变量和局部变量 
int dp[205][205];// 前i天生气度为j时的上线时间
int value[205][205];//第i天生气度为j时的上线时间 
int num[205];
int n, m, k;
void SetWeight(string s, int t){
    int sum=0;
    int nums[205];
    for(int i=0; i<m; i++)
        if(s[i]=='1')
            nums[sum++]=i;
    num[t]=sum;  //第t天总的生气度 
    int inhap, time;
    // 背包1  最小背包 
    for(int i=0; i<sum; i++){  //生气度 
        for(int j=0; j<=i; j++){  //生气度 
            inhap=sum-(i-j+1);    //上线i到j小时，产生inhap生气度 
            time=(nums[i]-nums[j]+1); //上线的小时 
            value[t][inhap]=min(time, value[t][inhap]);
        }
    }
    value[t][sum]=0; //花费sum的生气度需要上线0小时 
}
int main(){
    int T;
    cin >> T;
    while(T--){
        memset(dp, 0x3f3f, sizeof(dp));
        memset(value, 0x3f3f, sizeof(value));
        cin >> n >> m >> k;
        for(int i=0; i<=k; i++){
            dp[0][i]=0;
        }
        for(int i=1; i<=n; i++){
            string s;
            cin >> s;
            SetWeight(s, i);
        }
        //背包2 
        for(int i=1; i<=n; i++){ 
            for(int p=k; p>=0; p--){ //生气度 
                for(int j=0; j<=num[i]; j++){ //每一天的生气度 
                    if(p-j>=0)
                        dp[i][p] = min(dp[i][p], value[i][j]+dp[i-1][p-j]);
                        //前i天的生气度为p时有两种情况：其一是前i-1天的生气度为p-j时，第i天生气度为j 
						 
                }
            }
        }
        int ans=dp[n][0];
        for(int i=0; i<=k; i++){
            ans = min(ans, dp[n][i]);
        }
        cout << ans << endl;
    }
    return 0;
}
