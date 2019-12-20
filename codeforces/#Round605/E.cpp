#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int a[maxn], ans[maxn];
vector<int> G[maxn];
bool vis[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    queue<int> q;
    for(int i=0; i<n; i++){
        if(i+a[i] < n){
            if((a[i]%2) != (a[i+a[i]]%2)){
                vis[i] = 1;
                q.push(i);
                ans[i] = 1;
            }
            else{
                G[i+a[i]].push_back(i);
            }
        }
        if(i-a[i] >= 0){
            if((a[i]%2) != (a[i-a[i]]%2)){
                vis[i] = 1;
                q.push(i);
                ans[i] = 1;
            }
            else{
                G[i-a[i]].push_back(i);
            }
        }
    }

    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i=0; i<G[t].size(); i++){
            int v = G[t][i];
            if(!vis[v] && a[v]%2 == a[t]%2){
                ans[v] = ans[t]+1;
                q.push(v);
                vis[v]=1;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << (ans[i]==0 ? -1 : ans[i]) << " ";
    }
    cout << endl;
    return 0;
}