#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int a[maxn];

struct node{
    int x;
    int cnt;
    node(int x, int c):x(x), cnt(c){}
    friend bool operator<(node a, node b){
        return a.cnt > b.cnt;
    }
};
priority_queue<node> q;
void solve(){
    
    while(!q.empty()){
        q.pop();
    }
    int n;
    cin >> n;
    int x;
    map<int ,int> m;
    for(int i=0; i<n; i++){
        cin >> x;
        a[i] = x;
        if(x % 2 == 0){
            m[x]++;
        }
    }
    for(int i=0; i<n; i++){
        if(m[a[i]]){
            q.push(node(a[i], m[a[i]]));
            m[a[i]] = 0;
        }
    }
    int cnt = 0;
    map<int, int> vis;
    while(!q.empty()){
        node tp = q.top();
        q.pop();
        if(!vis[tp.x]){
            cnt++;
            vis[tp.x] = 1;
        }
        tp.x /= 2;
        if(tp.x % 2)
            continue;
        q.push(tp);
    }
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