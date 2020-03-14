#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int p[maxn], cnt[maxn];
void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 1e9, ansa, ansb, ansc;
    for (int i = 1; i <= 11000; i++){
        for (int j = 1; i * j <= 11000; j++){
            for (int k = 1; i * j * k <= 11000; k++){
                int A = i, B = i * j, C = i * j * k;
                if(ans > abs(A-a) + abs(B-b) + abs(C-c)){
                    ans = abs(A - a) + abs(B - b) + abs(C - c);
                    ansa = A, ansb = B, ansc = C;
                }
            }
        }
    }
    cout << ans << endl;
    cout << ansa << " " << ansb << " " << ansc << endl;
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