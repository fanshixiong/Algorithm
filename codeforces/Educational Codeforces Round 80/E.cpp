#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6+7;

int bit[maxn], a[maxn], max_a[maxn], min_a[maxn];
int pos[maxn];
int n, m;

int lowbit(int x){
    return x & (-x);
}

void update(int x, int op){
    while(x < maxn){
        bit[x] += op;
        x += lowbit(x);
    }
}
int get(int x){
    int ans=0;
    while(x){
        ans += bit[x];
        x -= lowbit(x);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    memset(bit, 0, sizeof(bit));
    for (int i = 1; i<=n; i++){
        max_a[i] = min_a[i] = i;
        pos[i] = i + m;
        update(i+m, 1);
    }
    for (int i = 0; i<m; i++){
        int x;
        cin >> x;
        min_a[x] = 1;
        max_a[x] = max(max_a[x], get(pos[x]));

        update(pos[x], -1);
        pos[x] = m - i;
        update(pos[x], 1);
    }
    for (int i = 1; i<=n; i++){
        max_a[i] = max(max_a[i], get(pos[i]));
    }
    for (int i = 1; i <= n; i++){
        cout << min_a[i] << " " << max_a[i] << endl;
    }
        return 0;
}