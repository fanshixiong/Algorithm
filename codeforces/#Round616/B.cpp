#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int a[maxn], l[maxn], r[maxn];
void solve(){
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++){
        cin >> a[i];
        l[i] = r[i] = 0;
    }
    for (int i = 0; i<n; i++){
        if(a[i]>=i){
            l[i] = 1;
            if(i>0 && l[i-1]==0)
                l[i] = 0;
        }
    }
    for (int i = n - 1; i >= 0; i--){
        if(a[i]>=n-i-1){
            r[i] = 1;
            if(i<n-1 && r[i+1]==0)
                r[i] = 0;
        }
    }
    for (int i = 0; i < n; i++){
        if(l[i]&&r[i]){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    //freopen("Bin.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}