#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair

const int maxa = 1e6 + 10;
const int maxn = 1e5 + 10;
int n, a[maxn], maxx;

vector<int> prime, p[maxa];
bool isprm[maxa], vis[maxa];

int totPrm;
vector<int> G[maxa];

int ans, dis[maxa];

void Prime(int x){
    memset(isprm, 1, sizeof(isprm));
    prime.pb(1); totPrm++;
    for (int i = 2; i <= x; i++){
        if(isprm[i]){
            prime.pb(i);
            totPrm++;
        }
        for (int j = 1; j < totPrm && i * prime[j] <= x; j++){
            isprm[i * prime[j]] = 0;
            if(i%prime[j] == 0){ break; }
        }
    }
}

void divide(int x){
    int var = x;
    for (int i = 2; i * i <= var; i++){
        if(x % i != 0)
            continue;
        int cnt = 0;
        while(x % i == 0){
            cnt++;
            x /= i;
        }
        if(cnt & 1){
            p[var].pb(i);
        }
    }
    if(isprm[x]){
        p[var].pb(x);
    }
}

bool bfs(){
    ans = 0x3f3f3f3f;
    for (int i = 0; i < totPrm; i++){
        if(prime[i] * prime[i] > maxx) break;
        queue<pair<int, int>> q;
        memset(dis, 0x3f3f3f3f, sizeof(dis));
        q.push(mk(prime[i], 0));
        dis[prime[i]] = 0;
        while(!q.empty()){
            pair<int, int> tmp = q.front();
            q.pop();
            int u = tmp.first, fa = tmp.second;
            for (int j = 0; j < G[u].size(); j++){
                int v = G[u][j];
                if(v == fa) continue;
                if(dis[v] == 0x3f3f3f3f && v != prime[i]){
                    dis[v] = dis[u] + 1;
                    q.push(mk(v, u));
                }
                else{
                    ans = min(ans, dis[u] + dis[v] + 1);
                }
            }
        }
    }
    if(ans == 0x3f3f3f3f)
        ans = -1;
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    Prime(maxx);
    for (int i = 0; i < n; i++){
        if(!vis[a[i]]){
            divide(a[i]);
        }
        vis[a[i]] = 1;
    }
    for (int i = 0; i < n; i++){
        if(p[a[i]].empty()){
            cout << 1 << endl;
            return;
        }
        if(p[a[i]].size() == 1)
            p[a[i]].pb(1);
        G[p[a[i]][0]].pb(p[a[i]][1]);
        G[p[a[i]][1]].pb(p[a[i]][0]);
    }
    bfs();
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}