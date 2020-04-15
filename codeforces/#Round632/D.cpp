#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 3050;
int a[maxn];
void solve(){
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    for (int i = 1; i <= n; i++){
        //printf("%c", s[i-1]);
        a[i] = (s[i - 1] == 'R');
    }
    vector<vector<int>> ans;
    int cnt = 0;
    while(1){
        vector<int> cur;
        for (int i = 1; i < n; i++){
            if (a[i] && (!a[i + 1])){
                cur.push_back(i);
                swap(a[i], a[i + 1]);
                i++;
            }
        }
        if(cur.empty()) break;
        cnt += cur.size();
        ans.push_back(cur);
    }

    if(cnt < k || (int)ans.size() > k){
        //cout << -1 << endl;
        printf("-1\n"); return;
    }
    int t = k - ans.size();
    for(auto cur : ans){
        while(cur.size() > 1 && t > 0){
            t--;
            //cout << 1 << " " << cur.back() << endl;
            printf("1 %d\n", cur.back());
            cur.pop_back();
        }
        //cout << cur.size() << " ";
        printf("%d ", (int)cur.size());
        for(auto x : cur){
            //cout << x << " ";
            printf("%d ", x);
        }
        //cout << endl;
        printf("\n");
    }
} 
int main(){
    //IOS;
    int t; t = 1;
    while(t--){
        solve();
    }
    return 0;
}