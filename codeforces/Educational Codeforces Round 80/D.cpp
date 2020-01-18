#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+7;
int n, m, ans_l, ans_r;
int num[1000];
int a[maxn][11];

bool judge(int mid){
    memset(num, 0, sizeof(num));
    for (int i = 0; i < n; i++){
        int x = 0;
        for (int j = 0; j < m; j++){
            if(a[i][j] >= mid)
                x += (1 << j);
        }
        num[x] = i + 1;
    }
    for (int i = 0; i < (1 << m); i++){
        for (int j = 0; j < (1 << m); j++){
            if(num[i] && num[j] && ((i|j) == ((1<<m)-1))){
                ans_l = num[i];
                ans_r = num[j];
                return true;
            }
        }
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    int l = -1, r = 1e9;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
            l = min(l, a[i][j]);
            r = max(r, a[i][j]);
        }
    }

    int ans = l;
    while(l<=r){
        int mid = (l + r) >> 1;
        if(judge(mid)){
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    judge(ans);
    cout << ans_l << " " << ans_r << endl;
    return 0;
}