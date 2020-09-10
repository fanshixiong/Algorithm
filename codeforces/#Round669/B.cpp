#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn], b[maxn];
void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(b, 0, sizeof b);

    int idx = 0, maxEle = 0;
    for (int i = 0; i < n; i++){
        if(a[i] > maxEle){
            maxEle = a[i];
            idx = i;
        }
    }

    b[0] = maxEle;
    a[idx] = 0;
    int g = maxEle;

    for (int i = 1; i < n; i++){
        maxEle = idx = 0;
        for (int j = 0; j < n; j++){
            if(!a[j])continue;

            int t = __gcd(g, a[j]);
            //cout << t << " ";
            if(t > maxEle){
                maxEle = t;
                idx = j;
                //cout << t << " " << idx << endl;
            }
        }
        //cout << endl;
        b[i] = a[idx];
        a[idx] = 0;
        g = maxEle;
    }

    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}