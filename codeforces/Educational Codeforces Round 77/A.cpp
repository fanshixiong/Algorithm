#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    while(n--){
        int c, sum;
        cin >> c >> sum;
        int t=sum/c;
        int res = sum - t*c;
        int cnt = res;
        long long ans = cnt*(t+1)*(t+1) + (c-cnt)*t*t;
        cout << ans << endl;
    }
    return 0;
}