#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int a[maxn], ans[maxn], vis[maxn];
void solve(){
    
    memset(vis, 0, sizeof(vis));
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    int x=1;
    int ma=-1;
    for(int i=0;i<n;i++){
        if(ma < a[i]){
            ans[i] = a[i];
            vis[a[i]]++;
            ma = a[i];
        }
        else{
            while(vis[x] && x<n)
                x++;
            if(x > ma){
                cout << -1 << endl;
                return;
            }
            else{
                ans[i] = x;
                vis[x]++;
            }
        }
        
    }
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
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