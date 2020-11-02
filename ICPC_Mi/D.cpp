#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 3e5 + 10;
 
int n,m;
int pre[maxn];
int u[maxn], v[maxn];

void init(){
    for (int i = 1; i <= n; i++) pre[i] = i;
}
 
int find(int x){
    return pre[x] == x ? x : pre[x] = find(pre[x]);
}
 
int main() {
    scanf("%d%d", &n, &m);
    init();
    for (int i = 0; i < m; i++){
        scanf("%d%d", &u[i], &v[i]);
        pre[find(u[i])] = pre[find(v[i])];
    }
    for (int i = 0; i < m; i++){
        int cnt = 0;
        int x = 
        for(int i = 1; i <= n; i++)
            if(pre[i] == i) {
                cnt++;
            }
        printf("%d ", cnt);
    }
 
    return 0;
}