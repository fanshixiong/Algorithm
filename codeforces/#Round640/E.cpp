#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 8e3 + 10;
int a[maxn], v[maxn];
void solve(){
    int n; cin >> n;
    //map<int, int> v; //不能用map
    for (int i = 1; i <= n; i++) cin >> a[i], v[a[i]]++;

    int cnt = 0;
    for (int l = 1; l <= n; l++){
        int sum = a[l];
        for (int r = l + 1; r <= n; r++){
            sum += a[r];
            if(sum < maxn && v[sum]){
                cnt += v[sum];  
                v[sum] = 0;
            }
        }
    }
    cout << cnt << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}