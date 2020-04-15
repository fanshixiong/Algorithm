#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 510;
int a[maxn][maxn];
void solve(){
    int n; cin >> n;
    if(n <= 2){
        cout << -1 << endl;
        return;
    }
    int t = n * n - 3 * 3;
    a[1][1] = t + 2, a[1][2] = t + 8, a[1][3] = t + 7;
    a[2][1] = t + 3, a[2][2] = t + 1, a[2][3] = t + 6;
    a[3][1] = t + 4, a[3][2] = t + 5, a[3][3] = t + 9;
    int cnt = 0;
    for (int i = n; i > 3; i--){
        if(i % 2 == 0){ //偶数
            for (int j = 1; j <= i; j++){
                a[j][i] = ++cnt; //列
            }
            for (int j = i - 1; j >= 1; j--){
                a[i][j] = ++cnt; //行
            }
        }
        else{ //奇数
            for (int j = 1; j <= i; j++){
                a[i][j] = ++cnt; // 行
            }
            for (int j = i - 1; j >= 1; j--){
                a[j][i] = ++cnt; //列
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    IOS;
    int t; t = 1;
    while(t--){
        solve();
    }
    return 0;
}