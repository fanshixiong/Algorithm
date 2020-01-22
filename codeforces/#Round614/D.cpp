#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
#define ll long long
ll x0[maxn], y0[maxn], ax, ay, bx, by;
ll xs, ys, t;
int tot = 1;
int judge(int x){
    int ans = 0;
    ll remain = 0, x_tmp = xs, y_tmp = ys;
    for (int i = x; i >= 0; i--){
        remain += abs(x0[i] - x_tmp) + abs(y0[i] - y_tmp);
        if(remain > t)
            return ans;
        x_tmp = x0[i];
        y_tmp = y0[i];
        ans++;
    }
    for (int i = x + 1; i <= tot; i++){
        remain += abs(x0[i] - x_tmp) + abs(y0[i] - y_tmp);
        if(remain > t)
            return ans;
        ans++;
        x_tmp = x0[i];
        y_tmp = y0[i];
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> x0[0] >> y0[0] >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    while(1){
        x0[tot] = x0[tot - 1] * ax + bx;
        y0[tot] = y0[tot - 1] * ay + by;
        //cout << x0[tot] << " " << y0[tot] << endl;
        if(x0[tot] > xs && y0[tot] > ys && x0[tot] + y0[tot] - xs - ys > t)
            break;
        tot++;
    }
    int ans = 0;
    for (int j = 0; j <= tot; j++){
        ans = max(ans, judge(j));
    }
    cout << ans << endl;
    return 0;
}