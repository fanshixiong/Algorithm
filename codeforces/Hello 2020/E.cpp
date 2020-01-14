#include <bits/stdc++.h>
using namespace std;
#define ll long double
const int maxn = 3005;
ll x[maxn], y[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    long long res = (long long)n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
    ll pi = acos(-1.0L);
    for (int i = 0; i < n; i++){
        vector<ll> v;
        for (int j = 0; j < n; j++){
            if(i == j)
                continue;
            v.push_back(atan2(y[j]-y[i], x[j]-x[i]));
        }
        sort(v.begin(), v.end());
        int m = n - 1, index = 0;
        for (int j = 0; j < m; j++){
            while(index<j+m){
                ll ang = v[index % m] - v[j];
                if(ang<0)
                    ang += pi * 2;
                if(ang<pi)
                    index++;
                else
                    break;
            }
            long long cnt = index - j - 1;
            res -= 1ll * cnt * (cnt - 1) * (cnt - 2) / 6;
        }
    }
    cout << res << endl;
    return 0;
}