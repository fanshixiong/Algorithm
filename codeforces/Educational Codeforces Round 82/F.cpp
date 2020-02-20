#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < (int)n; i++)

typedef pair<int, int> pt;

const int maxm = 310;
const int maxn = 2e6 + 10;

int n, m, q;
int a[maxm][maxm];

int dist[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};

bool in(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

int p[maxm*maxm], rk[maxm*maxm];

int getp(int v) {
    return p[v] == v ? v : p[v] = getp(p[v]);
}

bool unite(int a, int b) {
    a = getp(a); b = getp(b);
    if (a == b) return false;
    if (rk[a] < rk[b]) swap(a, b);
    p[b] = a;
    rk[a] += rk[b];
    return true;
}

int dif[maxn];
vector<pt> add[maxn], del[maxn];

void calc(const vector<pt>& ev, int coeff)  {
    forn(i, n) forn(j, m) a[i][j] = 0;
    forn(i, n * m) p[i] = i, rk[i] = 1;
        
    for (auto it : ev) {
        int cur = 1;
        int x = it.x / m, y = it.x % m;
        a[x][y] = 1;
        
        forn(k, 4) {
            int nx = x + dist[k][0];
            int ny = y + dist[k][1];
            if (in(nx, ny) && a[nx][ny] == 1)
                cur -= unite(nx * m + ny, x * m + y);
        }
        
        dif[it.y] += cur * coeff;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    int clrs = 1;
    forn(i, q) {
        int x, y, c;
        cin >> x >> y >> c;
        --x; --y;
        if (a[x][y] == c) continue;
        clrs = c + 1;
        add[c].pb(mp(x * m + y, i));
        del[a[x][y]].pb(mp(x * m + y, i));
        a[x][y] = c;
    }
    forn(x, n) forn(y, m)
        del[a[x][y]].pb(mp(x * m + y, q));
    
    forn(i, clrs) reverse(all(del[i]));
    
    forn(i, clrs) calc(add[i], +1);
    forn(i, clrs) calc(del[i], -1);
    
    int cur = 1;
    forn(i, q) {
        cur += dif[i];
        cout << cur << endl;
    }
    return 0;
}