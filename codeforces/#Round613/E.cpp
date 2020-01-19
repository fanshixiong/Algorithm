#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 4e5+7;
int n;
pair<int, int> a[maxn];
int ans[maxn];
void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        a[(i << 1) - 1] = make_pair(l, -i);
        a[i << 1] = make_pair(r, i);
        ans[i] = 0;
    }
    sort(a + 1, a + 1 + (n << 1));
    multiset<int> s;
    int c = 0;
    for (int i = 1; i <= 2 * n; i ++){
        if(a[i].second<0)
            s.insert(-a[i].second);
        else
            s.erase(s.find(a[i].second));
        if(s.size() == 0)
            c++;
        if(s.size() == 1 && a[i].second > 0 && a[i+1].second < 0 && a[i+1].first > a[i].first)
            ans[*s.begin()]++;
        if(s.size() == 1 && a[i].second<0 && a[i+1].second>0)
            ans[*s.begin()]--;
    }
    int res = -1;
    for (int i = 1; i<=n; i++){
        res = max(res, ans[i]);
    }
    cout << res + c << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}