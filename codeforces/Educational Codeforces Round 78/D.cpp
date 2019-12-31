#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
map<int, int> mp;
int par[maxn];
pair<int, int> p[maxn];
int n;

int find(int x){
    if(par[x] == x)
        return x;
    return par[x] = find(par[x]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        par[i] = i;
    for (int i = 1; i <= n; i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p+1, p + 1 + n);
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        auto it = mp.lower_bound(p[i].first);
        while(it != mp.end() && it->first < p[i].second){
            int u = find(i);
            int v = find(it->second);
            if(u == v || cnt >= n){
                cout << "NO" << endl;
                return 0;
            }
            cnt++;
            par[u] = v;
            it++;
        }
        mp[p[i].second] = i;
    }
    if(cnt == n-1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}