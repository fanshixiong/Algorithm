#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    string s;
    cin >> n >> s;
    int x = n-1;
    while(x>=0 && !((s[x]-'0')&1)){
        x--;
    }
    if(x==0){
        cout << -1 << endl;
        return;
    }
    string str, ans;
    int sum = 0;
    bool flg1 = false;
    for (int i = 0; i <= x; i++){
        int j = s[i] - '0';
        sum += j;
        str += s[i];
        if(!flg1 && (j&1) && i!=0 && i!=x){
            flg1 = true;
            continue;
        }
        ans += s[i];
    }
    if(sum==0){
        cout << -1 << endl;
        return;
    }
    if(sum & 1){
        if(flg1){
            cout << ans << endl;
        }
        else{
            cout << -1 << endl;
        }
    }else{
        cout << str << endl;
    }
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