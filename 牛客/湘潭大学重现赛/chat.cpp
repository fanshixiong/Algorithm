#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
//ȫ�ֱ����;ֲ����� 
int dp[205][205];// ǰi��������Ϊjʱ������ʱ��
int value[205][205];//��i��������Ϊjʱ������ʱ�� 
int num[205];
int n, m, k;
void SetWeight(string s, int t){
    int sum=0;
    int nums[205];
    for(int i=0; i<m; i++)
        if(s[i]=='1')
            nums[sum++]=i;
    num[t]=sum;  //��t���ܵ������� 
    int inhap, time;
    // ����1  ��С���� 
    for(int i=0; i<sum; i++){  //������ 
        for(int j=0; j<=i; j++){  //������ 
            inhap=sum-(i-j+1);    //����i��jСʱ������inhap������ 
            time=(nums[i]-nums[j]+1); //���ߵ�Сʱ 
            value[t][inhap]=min(time, value[t][inhap]);
        }
    }
    value[t][sum]=0; //����sum����������Ҫ����0Сʱ 
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
        //����2 
        for(int i=1; i<=n; i++){ 
            for(int p=k; p>=0; p--){ //������ 
                for(int j=0; j<=num[i]; j++){ //ÿһ��������� 
                    if(p-j>=0)
                        dp[i][p] = min(dp[i][p], value[i][j]+dp[i-1][p-j]);
                        //ǰi���������Ϊpʱ�������������һ��ǰi-1���������Ϊp-jʱ����i��������Ϊj 
						 
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
