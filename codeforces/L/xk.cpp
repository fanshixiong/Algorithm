#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m;
int a[maxn], maxsum[maxn][20];
vector<int> ans;

void RMQ(int num){
    for (int j = 1; (1<<j) <= num; j++){
        for (int i = 1; i+(1<<j)-1 <= num; i++){
            if(i+(1<<j)-1<=num){
                maxsum[i][j] = max(maxsum[i][j - 1], maxsum[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
}
void getsum(int x, int y){
    int z = 0;
    while((1<<(z+1)) <= y-x+1)
        z++;
    int res = max(maxsum[x][z], maxsum[y - (1 << z) + 1][z]);
    ans.push_back(res);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        maxsum[i][0] = a[i];
    }
    RMQ(n);
    
    getsum(1, n - m);
    int remain = m - 1;
    int i = find(a + 1, a + 1 + n, ans[0]) - a + 1;
    while(remain > 0 && (n-remain) - i != remain){
        // cout << ans[m-remain-1]  << " " << i << endl;
        getsum(i, n - remain + 1);
        remain--;
        i = find(a + 1 + i, a + 1 + n, ans[m - remain - 1]) - a + 1;
    }
    for(auto x : ans){
        cout << x << " ";
    }
    return 0;
}