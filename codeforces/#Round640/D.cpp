#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e3 + 10;
int a[maxn];
void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int pre_l = 0, pre_r = 0;
    int sum_l = 0, sum_r = 0;
    int l = 0, r = n - 1, i = 0;
    while(l <= r){
        int sum = 0;
        if(i % 2 == 0){
            while(l <= r && sum <= pre_r){
                sum += a[l++];
            }
            sum_l += sum;
            pre_l = sum;
        }
        else{
            while(l <= r && sum <= pre_l){
                sum += a[r--];
            }
            sum_r += sum;
            pre_r = sum;
        }
        i++;
    }
    cout << i << " " << sum_l << " " << sum_r << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}