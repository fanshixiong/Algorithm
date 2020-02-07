#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5+10;
int a[30], ans[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = n; i >= 1; i--){
        ans[i] = lower_bound(a + 1, a + 1 + cnt, s[i - 1] - 'a') - a; //在a数组里找1-cnt中的第一个大于等于s[i]的位置
        cnt = max(cnt, ans[i]);
        a[ans[i]] = s[i - 1] - 'a';
    }
    //cout << cnt << endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    if(cnt > 2){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++)
            cout << ans[i] - 1;
    }
    return 0;
}