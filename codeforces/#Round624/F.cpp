#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 2e5 + 10;
pair<int, int> a[maxn];
int v[maxn], n;
ll s1[maxn], s2[maxn];

int lowbit(int x){
    return x & (-x);
}
void add(int i, int x){
    while(i <= n){
        s1[i]++;
        s2[i] += x;
        i += lowbit(i);
    }
}
ll getsum(ll s[], int i){
    ll ans = 0;
    while(i > 0){
        ans += s[i];
        i -= lowbit(i);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].first;
    }
    for (int i = 1; i <= n; i++){
        cin >> v[i];
        a[i].second = v[i];
    }
    sort(a + 1, a + 1 + n);
    sort(v + 1, v + 1 + n);
    int *vent = unique(v+1, v+1+n);
    ll ans = 0ll;
    for (int i = 1; i<=n; i++){
        int pos = lower_bound(v + 1, vent, a[i].second) - v;

        ll sum1 = getsum(s1, pos), sum2 = getsum(s2, pos);
        ans += sum1 * a[i].first - sum2;
        add(pos, a[i].first);
    }
    cout << ans << endl;
    return 0;
}