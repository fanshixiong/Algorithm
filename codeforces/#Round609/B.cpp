#include<bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int a[maxn], b[maxn], tmpx[maxn];
int n, m;
bool judge(int x){
    memset(tmpx, 0, sizeof(tmpx));
    for(int i=0; i<n; i++){
        tmpx[i] = (a[i]+x)%m;
    }
    sort(tmpx, tmpx+n);
    for(int i=0; i<n; i++){
        if(tmpx[i] != b[i]){
            return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    sort(b, b+n);
    int ans = 0x3f3f3f3f;
    map<int, int> vis;
    for(int i=0; i<n; i++){
        int x = abs(b[i]-a[0]);
        if(!vis[x] && judge(x)){
            vis[x] = 1;
            ans = min(ans, x);
        }
        int x1 = (b[i]+m-a[0])%m;
        if(!vis[x1] && judge(x1)){
            vis[x1] = 1;
            ans = min(ans, x1);
        }
    }
    cout << ans << endl;
    return 0;
}