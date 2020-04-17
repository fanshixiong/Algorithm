#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn][210];
vector<vector<int> > pos(210);
void solve(){
    //memset(a, 0, sizeof a);
    int n; //cin >> n;
    scanf("%d", &n);
    for(int i = 1; i <= 200; i++) pos[i].clear();
    for(int i = 1; i <= n; i++){
        int x; scanf("%d", &x);
        pos[x].push_back(i);
        for(int k = 1; k <= 200; k++) a[i][k] = a[i - 1][k];
        a[i][x]++;
    }
    int ans = 0;
    for(int i = 1; i <= 200; i++) ans = max(ans, a[n][i]); //x的长度为零
    /* E1 - easy version 
    for(int l = 1; l <= n; l++){
        for(int r = l; r <= n; r++){
            int x = 0, y = 0;
            for(int k = 1; k <= 26; k++){
                x = max(x, min(a[l-1][k], a[n][k] - a[r][k]) * 2);
                y = max(y, a[r][k] - a[l-1][k]);
            }
            ans = max(ans, x + y);
        }
    }
    */
    for(int i = 1; i <= 200; i++){ //枚举字母
        int sz = pos[i].size();
        for(int j = 0; j < sz / 2; j++){ //枚举x长度
            int l = pos[i][j], r = pos[i][sz - j - 1];  // x=第一段x的结束为止，第二段x的开始位置
            ans = max(ans, (j + 1) * 2);                //y的长度为零。
            for (int k = 1; k <= 200; k++){
                ans = max(ans, (j + 1) * 2 + a[r - 1][k] - a[l][k]);
            }
        }
    }
    //cout << ans << endl;
    printf("%d\n", ans);
}
int main(){
    //IOS; int t; cin >> t;
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}