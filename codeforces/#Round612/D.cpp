#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n;
int p[maxn], c[maxn];
vector<int> G[maxn];
int a[maxn];


vector<int> dfs(int x){
    vector<int> ans;
    for (int i = 0; i < G[x].size(); i++){
        vector<int> tmp = dfs(G[x][i]);
        for (int j = 0; j < tmp.size(); j++)
            ans.push_back(tmp[j]);
    }
    if(x==0)
        return ans;
    if(ans.size() < c[x]){
        cout << "NO" << endl;
        exit(0);
    }
    vector<int> ne;
    for (int i = 0; i < c[x]; i++){
        ne.push_back(ans[i]);
    }
    ne.push_back(x);
    for (int i = c[x]; i < ans.size(); i++){
        ne.push_back(ans[i]);
    }
    ans = ne;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> p[i] >> c[i];
        G[p[i]].push_back(i);
    }
    vector<int> ans = dfs(0);
    cout << "YES" << endl;
    for (int i = 0; i < ans.size(); i++){
        a[ans[i]] = i+1;
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}