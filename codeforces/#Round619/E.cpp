#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i <= b; i++)
const int maxn = 505 + 4;

string s[maxn];
int n, q, m, sum[maxn][maxn][4], a[maxn][maxn];
int f[10][10][maxn][maxn], lg[maxn];

void Build_2D_Sparse_Table(int n, int m){
    for (int i = 1; i<=n; i++){
        for (int j = 1; j <= m; j++){
            f[0][0][i][j] = a[i][j];
        }
    }
    for (int i = 2; i < maxn; i++)
        lg[i] = 1 + lg[i / 2];

    for (int i = 1; i <= n; i++){
        for (int k2 = 1; (1 << k2)<=m; k2++){
            for (int j = 1; j <= m - (1 << k2); j++){
                f[0][k2][i][j] = max(f[0][k2 - 1][i][j], f[0][k2 - 1][i][j + (1 << (k2 - 1))]);
            }
        }
    }

    for(int k1 = 1; (1 << k1) <= n; k1++){
        for(int i = 1; i <= n - (1 << k1) + 1; i++){
            for(int k2 = 0; (1 << k2) <= m; k2++){
                for(int j = 1; j <= m - (1 << k2) + 1; j++){
                    f[k1][k2][i][j] = max(f[k1 - 1][k2][i][j], f[k1 - 1][k2][i + (1 << (k1 - 1))][j]);
                }
            }
        }
    }
}
int Query(int x1, int y1, int x2, int y2){
    int k1 = lg[x2 - x1 + 1], k2 = lg[y2 - y1 + 1];
    x2 = x2 - (1 << k1) + 1;
    y2 = y2 - (1 << k2) + 1;
    return max(max(f[k1][k2][x1][y1], f[k1][k2][x1][y2]), max(f[k1][k2][x2][y1], f[k1][k2][x2][y2]));
}
int getsum(int x1, int y1, int x2, int y2, int c){
    if (x1 < 1 || x1 > n || x2 < 1 || x2 > n || y1 < 1 || y1 > m || y2 < 1 || y2 > m)
        return 0;
    return sum[x2][y2][c] - sum[x1 - 1][y2][c] - sum[x2][y1 - 1][c] + sum[x1-1][y1-1][c];
}
bool check(int x, int y, int val){
    if (getsum(x - val + 1, y - val + 1, x, y, 0) < val * val)
        return false;
    if (getsum(x - val + 1, y + 1, x, y + val, 1) < val * val)
        return false;
    if (getsum(x + 1, y - val + 1, x + val, y, 2) < val * val)
        return false;
    if (getsum(x + 1, y + 1, x + val, y + val, 3) < val * val)
        return false;
    return true;
}
bool check2(int r1, int c1, int  r2, int c2, int mid){
    if(r1 > r2 || c1 > c2)
        return false;
    return Query(r1, c1, r2, c2) >= mid;
}
int main(){
    ios_base::sync_with_stdio(0);
    //while(~scanf("%d%d%d", &n, &m, &q)){
    while (cin >> n >> m >> q){
        rep(i, 1, n){
            cin >> s[i];
        }
        memset(sum, 0, sizeof(sum));

        rep(i, 1, n){
            rep(j, 1, m){
                rep(k, 0, 3){
                    sum[i][j][k] = sum[i - 1][j][k] + sum[i][j - 1][k] - sum[i - 1][j-1][k];
                }
                if(s[i][j-1] == 'R')
                    sum[i][j][0]++;
                if(s[i][j-1] == 'G')
                    sum[i][j][1]++;
                if(s[i][j-1] == 'Y')
                    sum[i][j][2]++;
                if(s[i][j-1] == 'B')
                    sum[i][j][3]++;
            }
        }
        rep(i, 1, n){
            rep(j, 1, m){
                int l = 0, r = min(n, m), ans = 0;
                while(l<=r){
                    int mid = (l + r) >> 1;
                    if(check(i, j, mid)){
                        ans = mid;
                        l = mid + 1;
                    }
                    else
                        r = mid - 1;
                }
                a[i][j] = ans;
            }
        }

        Build_2D_Sparse_Table(n, m);
        while(q--){
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            int l = 0, r = min(n, m), ans = 0;
            while(l<=r){
                int mid = (l + r) >> 1;
                if(check2(r1+mid-1, c1+mid-1, r2-mid, c2-mid, mid)){
                    l = mid + 1;
                    ans = 4 * mid * mid;
                }
                else
                    r = mid - 1;
            }
            cout << ans << endl;
        }
    }

    return 0;
}