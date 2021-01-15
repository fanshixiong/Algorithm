#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;

int w[maxn], h[maxn];
int n, k;

bool check(int a) {
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        num += (w[i] / a) * (h[i] / a);
        if (num >= k) return true;
    }
    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> h[i] >> w[i];
    int l = 1, r = 1e5;
    while (l < r)
    {
        int mid = l + (r - l + 1 >> 1);
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r;
}