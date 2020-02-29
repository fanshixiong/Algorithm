#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;

void solve(){
    int a[3], ans=0;
    for (int i = 0; i < 3; i++){
        cin >> a[i];
        if(a[i]){
            a[i] --;
            ans ++;
        }
    }
    sort(a, a + 3);
    if(a[0] >= 3){
        cout << 7 << endl;
        return;
    }
    
    
    if(a[0] && a[1] && a[2] && a[0] >= 2){
        cout << ans + 3 << endl;
        return;
    }
    if(a[0] && a[1] && a[2] && a[2] >= 2){
        cout << ans + 2 << endl;
        return;
    }
    if((!a[0] && a[1] && a[2]) || (a[0]==1 && a[1]==1 && a[2]==1)){
        cout << ans + 1 << endl;
        return;
    }
    if(!a[0] && !a[1] && a[2]){
        cout << ans << endl;
        return;
    }
    cout << ans << endl;
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