#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
struct node{
    int x, y;
    node (int x, int y):x(x), y(y){}
};
int cnt[maxn];
bool cmp(node &a, node &b){
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
void solve(){
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    vector<node> a;
    int mi=1e9, ma=0;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        ma = max(ma, x);
        mi = min(mi, y);
        a.push_back(node(x, y));
        //for(int j=x; j<=y; j++)
        //    cnt[j]++;
    }
    //sort(a.begin(), a.end(), cmp);
    int len = ma-mi;
    /*
    while(cnt[mi]>n-1){
        mi++;
    }
    while(cnt[ma]>n-1){
        ma--;
    }
    
    len = ma-mi;
    */
    if(len <= 0)
        cout << 0 << endl;
    else cout << len << endl;
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