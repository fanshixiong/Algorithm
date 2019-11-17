#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
const int maxn = 2010;

int n, m;
int dp[maxn][maxn][3], sum[maxn][maxn][3], R[maxn][maxn][3];

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    if(n == 1 && m == 1){
        cout << 1 << endl;
        return 0;
    }
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            if(s[j]=='R')
                R[i][j][0]=R[i][j][1]=1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=1; j<m; j++){
            R[i][j][0] += R[i][j-1][0];
        }
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            R[i][j][1] += R[i-1][j][1];
        }
    }
    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << R[i][j][1] << " ";
        }
        cout << endl;
    }
    */
    dp[0][0][0] = dp[0][0][1] = 1;
    sum[0][0][0] = sum[0][0][0] = 1;
    for(int i=1; i<n; i++){
        if(R[n-1][0][1] <= n-i-1) 
            dp[i][0][1] += dp[i-1][0][1];
        sum[i][0][0] = dp[i][0][1];
    }
    for(int j=1; j<m; j++){
        if(R[0][m-1][0] <= m-j-1)
            dp[0][j][0] += dp[0][j-1][0];
        sum[0][j][1] = dp[0][j][0];
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            int l=0, r=i-1, t, res=-1;
            while(l<=r){
                int mid = (l+r)/2;
                t = R[n-1][j][1]-R[mid][j][1];
                if(t <= n-i-1){
                    res=mid;
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            if(res >= 0){
                int tmp = res == 0 ? 0 : sum[res-1][j][1];
                dp[i][j][1] = (sum[i-1][j][1]-tmp+mod)%mod;
            }
            sum[i][j][0] = (sum[i][j-1][0]+dp[i][j][1])%mod;
            l=0; r=j-1; res=-1;
            while(l<=r){
                int mid=(l+r)/2;
                t = R[i][m-1][0]-R[i][mid][0];
                if(t <= m-j-1){
                    res = mid;
                    r=mid-1;
                }
                else
                    l=mid+1;
                    
            }
            if(res >= 0){
                int tmp = res==0?0:sum[i][res-1][0];
                dp[i][j][0] = (sum[i][j-1][0]-tmp+mod)%mod;
            }
            sum[i][j][1] = (sum[i-1][j][1]+dp[i][j][0])%mod;
        }
    }
    cout << (dp[n-1][m-1][0]+dp[n-1][m-1][1])%mod << endl;
    return 0;
}