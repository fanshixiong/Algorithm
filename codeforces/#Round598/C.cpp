#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int maxn = 1e5+10;
int dp[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    bool flg=0;
    dp[0]=1;
    if(s[0]=='w' || s[0]=='m')
        flg=1;
    for(int i=1; i<s.size(); i++){
        dp[i] = dp[i-1];
        if(s[i]=='w' || s[i]=='m')
            flg=1;
        if((s[i-1]=='u' && s[i]=='u') || (s[i-1]=='n' && s[i]=='n')){
            if(i==1)
                dp[i] = (dp[i-1]+1)%mod;
            else
                dp[i] = (dp[i-1]+dp[i-2])%mod;
            
        }
    }
    if(flg)
        cout << 0 << endl;
    else
        cout << dp[s.size()-1]%mod << endl;
    return 0;
}