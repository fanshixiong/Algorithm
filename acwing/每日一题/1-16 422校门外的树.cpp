#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
PII seg[N];

int main() {
    cin >> m >> n;

    for (int i = 0; i < n; i ++ ) cin >> seg[i].first >> seg[i].second;

    sort(seg, seg + n);

    int res = m + 1;
    int st = seg[0].first, ed = seg[0].second;
    for (int i = 1; i < n; i ++ )
        if (seg[i].first <= ed) ed = max(seg[i].second, ed);
        else {
            res -= ed - st + 1;
            st = seg[i].first, ed = seg[i].second;
        }

    res -= ed - st + 1;

    cout << res << endl;

    return 0;
}