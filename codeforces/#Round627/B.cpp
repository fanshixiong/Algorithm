#include<bits/stdc++.h>
using namespace std;
const int maxn = 50500;
pair<int, int> a[maxn];
int cnt[maxn];
void solve(){
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
        cnt[a[i].first]++;
    }
    sort(a, a + n);
    for (int i = 1; i < n; i++){
        if(cnt[a[i].first] >= 3){
            cout << "YES" << endl;
            return;
        }
        if(a[i].first == a[i-1].first){
            //cout << a[i - 1].second << " " << a[i].second << endl;
            if(a[i-1].second+1 != a[i].second && a[i-1].second != a[i].second+1){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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