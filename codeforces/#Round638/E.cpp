/*
显然，同颜色的框会很多，而同树的框最多n个。即每棵树最多1个。

因为一旦一棵树的框多于1，其可以转化为多个同颜色框+1个同树框。

所以问题就变成了n个树，每棵树可以选择用不用同树框。这其实就是一个01背包的变形。

dp[i][j][k]表示执行到前i颗树，红色剩j个，蓝色剩k个，的状态，最大满筐数是多少。

这样是个n^4的dp，根据经验，可以省去蓝色的那一维，转而用总量减去红色剩余量来表示剩余的蓝色浆果。

所以：dp[i][j]表示执行到前i颗树，红色剩j个.的状态，最大满筐数是多少。

遍历i时，枚举s，表示这一同树框中放红色浆果s个，蓝色k-s个。枚举时保证合法性。

再枚举j，用dp[i-1][j]来更新当前状态。

设nm1表示当前装s个红色浆果到同树框后，红色浆果剩余量，显然：nm1=j+a[i]-s,

sm表示1-i树上总浆果数

同理nm2表蓝色剩余,nm2=sm-dp[i-1][j]*k-k-nm1.

然后考虑转移：dp[i][nm1%k]=max(dp[i][nm1%k],dp[i-1][j]+nm1/k+nm2/k+1); 即装完同树框后，看蓝色与红色能否再装同色框。

枚举完s时加上一个当前数不装同树框的转移即可。

结果为dp[n][j]最大值。

这里注意一个细节。。int取模比long long 快个常数，这题刚好卡这个。
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 500 + 10;
int a[maxn], b[maxn];
ll dp[maxn][maxn];//前i棵树，剩j个红浆果的状态，最大装筐数 
void solve(){
    int n, k; cin >> n >> k;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    dp[0][0] = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++){
        sum += a[i] + b[i];
        for (int j = 0; j < k; j++){
            if(dp[i-1][j]<0)continue;//不合法状态不能往后转移
            for (int s = 1; s < k && s <= a[i]; s++){ //这一筐装红浆果多少个
                if(k-s > b[i]) continue;//不合法状态不能往后转移
                int num1 = j + a[i] - s;//红浆果剩余量
                int num2 = sum - num1 - k - dp[i - 1][j] * k;
                dp[i][num1 % k] = max(dp[i][num1 % k], dp[i - 1][j] + num1 / k + num2 / k + 1);
            }
            int num1 = j + a[i], num2 = sum - num1 - dp[i - 1][j] * k;
            dp[i][num1 % k] = max(dp[i][num1 % k], dp[i - 1][j] + num1 / k + num2 / k );//当前树不装同一树类型的筐
        }
    }
    ll ans = 0;
    for (int j = 0; j < k; j++) ans = max(ans, dp[n][j]);
    cout << ans << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}