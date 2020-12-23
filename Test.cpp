#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

#define pb push_back
const int maxn = 5e3+10;
vector<int> G[maxn];
int vis[maxn];
int tans, s;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param n int整型 
     * @param u int整型vector 
     * @param v int整型vector 
     * @return int整型
     */
    void dfs(int u, int dep){
        vis[u] = 1;
        if(dep > tans){
            tans = dep;
            s = u;
            cout << s << " " << tans << endl;
        }
        for(auto v : G[u]){
            if(vis[v]) continue;
            dfs(v, dep+1);
        }
    }
    int MaxDiameter(int n, vector<int>& u, vector<int>& v) {
        // write code here
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                G[u[j]].pb(v[j]);
                G[v[j]].pb(u[j]);
            }
            
            memset(vis, 0, sizeof vis);
            tans = -1; dfs(1, 0);
            
            memset(vis, 0, sizeof vis);
            tans = -1; dfs(s, 0);
            
            ans = max(ans, tans);
        }
        return ans;
    }
};
int main(){
    int n; cin >> n;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++) cin >> l[i];
    for(int i = 0; i < n; i++) cin >> r[i];

    Solution *s = new Solution();
    s->MaxDiameter(n, l, r);
    return 0;
}
/*
4
1 2 3 4
2 3 1 3
*/