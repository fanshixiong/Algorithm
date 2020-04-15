//考虑二进制。

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int n;
    cin >> n; 
    if(n <= 50){
        for (int i = 1; i <= n; i++) cout << i << " " << 1 << endl;
        return;
    }
    n -= 30;
    int sum = 0;
    bool left = true;
    for (int i = 1; i <= 30; i++){
        if(left) cout << i << " " << 1 << endl;
        else cout << i << " " << i << endl;

        if(n & 1){
            if(left){
                for (int j = 2; j <= i; j++) cout << i << " " << j << endl;
            }
            else{
                for (int j = i - 1; j >= 1; j--) cout << i << " " << j << endl;
            }
            left = !left;
            ++sum;
        }
        n >>= 1;
    }

    for (int i = 31; i <= sum + 30; i++){
        if(left) cout << i << " " << 1 << endl;
        else cout << i << " " << i << endl;
    }
}
int main(){
    IOS;
    int t, k = 0;
    cin >> t;
    while(k++ < t){
        cout << "Case #" << k << ":" << endl;
        solve();
    }
    return 0;
}