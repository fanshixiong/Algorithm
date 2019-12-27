#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool judge(int res, int d){
    ll dot = (1+res) * res/2;
    if(dot < d)
        return false;
    return dot%2 == d%2;
}
void solve(){
    ll a, b;
    cin >> a >> b;
    int res=1;
    int d = abs(a-b);
    if(d == 0){
        cout << 0 << endl;
        return;
    }
    while(!judge(res, d)){
        res++;
    }
    cout << res << endl;
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