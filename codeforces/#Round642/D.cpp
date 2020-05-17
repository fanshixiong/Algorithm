#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
struct cmp{
    bool operator()(const pair<int, int> p1, const pair<int, int> p2){
        if(p1.second - p1.first == p2.second - p2.first) return p1.first > p2.first;
        return p1.second - p1.first < p2.second - p2.first;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;
void solve(){
    int n, m; cin >> n;
    q.push(make_pair(1, n));
    int cnt = 0;
    while(!q.empty()){
        pair<int, int> p = q.top(); q.pop();
        int mid = (p.second + p.first) / 2;
        a[mid] = ++cnt;
        if(mid - p.first >= 1) q.push(make_pair(p.first, mid-1));
        if(p.second - mid >= 1) q.push(make_pair(mid+1, p.second));
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}