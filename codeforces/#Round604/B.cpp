#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int n, a[maxn];
void solve1(){
    memset(a, 0, sizeof(a));
    cin >> n;
    vector<pair<int ,int> > pr;
    for(int i=0; i<n; i++){
        cin >> a[i];
        pr.push_back({a[i], i});
    }
    sort(pr.begin(), pr.end());
    int vis[n+1]={0}, maxw = 1;
    vis[0] = 1;
    int pos = pr[0].second;
    for(int i=1; i<n; i++){
        int tmp = abs(pr[i].second - pos);
        if(maxw <= tmp) {
            vis[tmp] = 1;
            maxw = tmp;
            pos = pr[i].second;
        }
    }
    for(int i=0; i<n; i++)
        cout << vis[i];
    cout <<endl;
}
void solve2(){
    memset(a, 0, sizeof(a));
    cin >> n;
    vector<pair<int ,int> > pr;
    for(int i=0; i<n; i++){
        cin >> a[i];
        pr.push_back({a[i], i});
    }
    sort(pr.begin(), pr.end());
    int vis[n+1]={0}, maxw = 1;
    vis[0] = 1;
    int l, r;
    l = r = pr[0].second;
    cout << 1;
    for(int i=1; i<n; i++){
        l = min(l, pr[i].second);
        r = max(r, pr[i].second);
        if(r-l == i)
            cout << 1;
        else
            cout << 0;
    }
    cout<< endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve1();
    }
    return 0;
}