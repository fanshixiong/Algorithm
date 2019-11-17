#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int depth[maxn], n;
vector<int> son[maxn];
vector<int> order;

bool cmp(int x, int y){
    return depth[x] < depth[y];
}
void dfs1(int x){
    for(int i=0; i<son[x].size(); i++){
        dfs1(son[x][i]);
        depth[x] = max(depth[x], depth[son[x][i]]+1);
    }
    sort(son[x].begin(), son[x].end(), cmp);
}
void dfs2(int x){
    cout << x << " ";
    for(int i=0; i<son[x].size(); i++){
        dfs2(son[x][i]);
        if(i==0) continue;
        for(int j=0; j<=depth[son[x][i-1]]; j++){
            order.push_back(son[x][i]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i=1; i<n; i++){
        int x;
        cin >> x;
        son[x].push_back(i);
    }
    dfs1(0);
    dfs2(0);
    cout << endl << order.size() << endl;
    for(int i=0; i<order.size(); i++)
        cout << order[i] << " ";
    cout << endl;
    return 0;
}