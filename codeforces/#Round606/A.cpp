#include<bits/stdc++.h>
using namespace std;
#define ll long long
int cont[11] = {0, 0, 9, 18, 27, 36, 45, 54, 63, 72, 81};
int ct[11] = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
void solve(){
    ll x;
    cin >> x;

    int n = 0, tp=x;

    vector<int> c;
    while(tp){
        n++;
        c.push_back(tp%10);
        tp/=10;
    }
    int y = n-1;
    if(n==1){
        cout << x << endl;
        return;
    }
    ll cnt = cont[n] + ct[c[y]];
    int t=0;
    tp = n;
    while(tp){
        t = t*10+c[y];
        tp--;
    }
    if(x >= t && c[y] != 0)
        cnt++;
    cout << cnt << endl;
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