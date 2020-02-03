#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e4 + 10;
//int a[maxn][maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector< vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j<m; j++){
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    ll ans = 0;
    for (int j = 0; j < m; j++){
        vector<int> cnt(n);
        for (int i = 0; i < n; i ++){
            if(a[i][j] % m == j){
                int pos = a[i][j] / m;
                if(pos < n){
                    cnt[(i + n - pos) % n]++;
                }
                //else
                //    cnt[(pos - n) % n]++;
            }
        }
        int tmp = n - cnt[0];
        
        for (int i = 1; i < n; i++){
            tmp = min(tmp, i + n - cnt[i]);
        }
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}