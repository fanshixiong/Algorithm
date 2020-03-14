#include<bits/stdc++.h>
using namespace std;

int layer[5005], num[5005];

void solve(){
    memset(num, 0, sizeof num);
    int n, d;
    cin >> n >> d;
    int sum = n * (n - 1) / 2, dep = 0, minn = 0;
    num[0] = 1;
    for (int i = 2; i <= n; i++){
        if((i&(i-1)) == 0)
            dep++;
        minn += dep;

        layer[i - 1] = i - 1;
        num[i - 1] = 1;
    }
    if(d < minn || d > sum){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    dep = 1;
    for (int i = n-1; i > 0 && sum > d; i--){
        sum -= i;
        num[i]--;
        if(sum > d){
            layer[i] = dep;
            sum += dep;

            if(++num[dep] == (1 << dep))
                dep++;
        }
        else{
            int dif = d - sum;
            if(dif >= dep){
                layer[i] = dif;
                sum += dif;
                num[dif]++;
                break;
            }
            else{
                layer[i] = dep;
                sum += dep;
                if(++num[dep] == (1<<dep))
                    dep++;
            }
        }
    }

    int id(2), fid(1);
    for (int i = 1; num[i]; i++){
        for (int j = 0; j < num[i]; j++){
            layer[id++] = fid + j / 2;
        }
        fid += num[i - 1];
    }
    for(int i = 2; i <= n; i++){
        cout << layer[i] << " ";
    }
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}