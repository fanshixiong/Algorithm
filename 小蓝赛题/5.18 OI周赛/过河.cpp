#include<bits/stdc++.h>
using namespace std;
const int maxn = 150;
const int maxl = 300 * 105;

int L,s,t,m,stone[maxn],a[maxn],dp[maxl],base;
//stone就是石头的初始位置；a为我们将石头初始化后的石头位置；
bool vis[maxl];
//标记一下坐标上的该点是否为石头；
int main()
{
    ios::sync_with_stdio(0);// 加快cin的速度
    cin >> L;
    cin >> s >> t >> m;
    base = s * t;
    for(int i = 1 ; i <= m ; ++ i)
        cin >> stone[i];
    sort(stone + 1,stone + 1 + m);
//  判段s == t的情况
    if(s == t){
        int cnt =0;
        for(int i = 1 ; i <= m ; ++ i)
            if(stone[i] % s == 0)cnt++;
        cout << cnt << endl;
        return 0;
    }
    for(int i = 1 ; i <= m ; ++ i){//    离散化过程
        int d = stone[i] - stone[i - 1];
        if(d >= base)d = base;
        a[i] = a[i - 1] + d;
        vis[a[i]] = 1;
    }
    L = a[m] + base;
//  将L变成最后一个石头的位置+s*t
//  如果L - a[m] >= s * t就缩成s * t
//  如果L - a[m] <= s * t就加上一个数使得它等于这个距离因为青蛙可能跳出独木桥
    memset(dp,0x7f,sizeof(dp));
    dp[0] = 0;
    for(int i = 1 ; i <= L ; ++ i)
        for(int j = s ; j <= t ; ++ j){
            if(i - j >= 0){
                if(vis[i])dp[i] = min(dp[i - j] + 1,dp[i]);
                else dp[i] = min(dp[i - j],dp[i]);
            }
        }
    int ans = maxn;
    for(int i = a[m] ; i <= L ; ++ i)
        ans = min(ans,dp[i]);
    cout << ans << endl;
    return 0;
}
