#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define pi pair<int, int>
#define pb push_back
const int maxn = 1e6 + 10;

int f[maxn], w[3*maxn], u[maxn*3], v[maxn*3], p[maxn*3];

int n, m, s, t; 
int L, R;

void init(){
    for(int i = 0; i <= n; i++) f[i] = i;
}

int find(int x){
    if(x == f[x]) return x;
    return f[x] = find(f[x]);
}

void union1(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    f[y] = x;
}

bool cmp(int a, int b){
    return w[a] > w[b];
}

void solve(){
    scanf("%d%d%d%d", &n, &m, &s, &t);

    for(int i = 0; i < m; i++) p[i] = i;
    for(int i = 0; i < m; i++) scanf("%d%d%d", &u[i], &v[i], &w[i]);

    sort(p, p+m, cmp);
    // for(int i = 0; i < m; i++) cout << w[p[i]] << endl;

    init();
    for(int i = 0; i < m; i++){
        int x = u[p[i]], y = v[p[i]], wi = w[p[i]];
        // cout << x << " " << y << " " << wi << endl;
        union1(x, y);

        if(find(s) == find(t)){
            L = wi;
            break;
        }
    }

    init();
    for(int i = m-1; i >= 0; i--){
        int x = u[p[i]], y = v[p[i]], wi = w[p[i]];
        if(wi < L) continue;
        union1(x, y);

        if(find(s) == find(t)){
            R = wi;
            break;
        }
    }

    printf("%d %d\n", L, R);
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}