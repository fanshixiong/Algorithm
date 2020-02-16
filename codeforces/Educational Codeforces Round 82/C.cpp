#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;
string s;
vector<int> G[27];
bool vis[27], flg[27];
void solve(){
    cin >> s;
    int n = s.size();

    if(n <= 2){
        cout << "YES" << endl;
        cout << s;
        for (int i = 0; i < 26; i++){
            if (i + 'a' == s[0] || (s.size() == 2 && i + 'a' == s[1])){
                continue;
            }
            cout << (char)(i + 'a');
            
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < 26; i++)
        G[i].clear();
    memset(vis, 0, sizeof(vis));
    memset(flg, 0, sizeof(flg));

    for (int i = 0; i < n - 1; i++){
        int c1 = s[i] - 'a', c2 = s[i + 1] - 'a';
        if(find(G[c1].begin(), G[c1].end(), c2) == G[c1].end())
            G[c1].push_back(c2);
        if(find(G[c2].begin(), G[c2].end(), c1) == G[c2].end())
            G[c2].push_back(c1);
        flg[c1] = 1; flg[c2] = 1;

        if(G[c2].size() > 2 || G[c1].size() > 2){
            cout << "NO" << endl;
            return;
        }
    }


    int pos = -1, cnt = 0;
    for (int i = 0; i < 26; i++){
        if(flg[i] && G[i].size()==1){
            pos = i;
            cnt++;
        }
    }


    if(pos == -1 || cnt != 2){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    queue<int> q;
    vis[pos] = 1;
    q.push(pos);
    cout << char(pos + 'a');
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(!q.empty() && G[t].size()==1)
            continue;
        for (int i = 0; i < G[t].size(); i++){
            int u = G[t][i];
            if(!vis[u]){
                cout << (char)(u + 'a');
                q.push(u);
                vis[u] = 1;
            }
        }
    }
    for (int i = 0; i < 26; i++){
        if(!flg[i])
            cout << (char)(i + 'a');
    }
    cout << endl;
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