#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 1e6 + 10;
int cnt[maxn], a[maxn];

int lowbits(int x){
    return x & (-x);
}

void add(int x, int op){
    while(x < maxn){
        cnt[x] += op;
        x += lowbits(x);
    }
}

int query(int x){
    int res = 0;
    while(x){
        res += cnt[x];
        x -= lowbits(x);
    }
    return res;
}

void solve(){
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        add(x, 1);
    }
    while(q--){
        int x; cin >> x;
        if(x < 0){
            x = -x;
            int sum = 0;
            int l = 0, r = maxn, mid;
            while(l <= r){
                mid = (l + r) / 2;
                if(query(mid) >= x){
                    sum = mid;
                    r = mid - 1;
                } else l = mid + 1;
            }
            add(sum, -1);
        }
        else{
            add(x, 1);
        }
    }

    int pos = 0;
    for (int i = 1; i <= n; i++){
        if(query(i) > 0){
            pos = i;
            break;
        }
    }
    cout << pos << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}