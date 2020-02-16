#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int maxn = 110;
struct node{
    ll ti, hi, li;
}cus[maxn];
bool cmp(node &a, node &b){
    return a.ti < b.ti;
}
void solve(){
    int n;
    ll m;
    cin >> n >> m;
    ll T = m;
    for (int i = 1; i <= n; i++){
        cin >> cus[i].ti >> cus[i].li >> cus[i].hi;
    }
    sort(cus + 1, cus + n + 1, cmp);
    ll tl = T, th = T;
    for (int i = 1; i <= n; i++){
        ll delta = (cus[i].ti - cus[i - 1].ti);
        tl -= delta, th += delta;
        node v = cus[i];
        if(th < v.li || tl > v.hi){
            //cout << i<< " " << tl << " " << th << endl << endl;
            cout << "NO" << endl;
            return;
        }
        else{
            if(v.li <= th && v.li >= tl && v.hi >= th){
                tl = v.li;
            }
            if(v.li <= tl && tl <= v.hi && v.hi <= th){
                th = v.hi;
            }
            if(v.li <= tl && tl <= th && th <= v.hi){
            }
            if(tl <= v.li && v.hi <= th){
                tl = v.li, th = v.hi;
            }
        }
    }
    cout << "YES" << endl;
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