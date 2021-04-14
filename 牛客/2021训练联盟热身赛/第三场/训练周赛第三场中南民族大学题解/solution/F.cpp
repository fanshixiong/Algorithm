#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;

int n;
int motherlode;
vector<int> p, x, y, worst, profit, invest;
vector<vector<int> > G;
priority_queue<pii, vector<pii>, greater<> > pq;

int worst_case(int cur) {
    int res = 0;
    for (int u:G[cur])
        res += worst_case(u);
    return max(y[cur] - 1, y[cur] - x[cur] + res);
}

int get_profit(int cur) {
    int childInvest = oo;
    profit[cur] = x[cur] - y[cur];
    for (int u:G[cur]) {
        profit[cur] += max(0, get_profit(u));
        if (profit[u] > 0) childInvest = min(childInvest, invest[u]);
    }
    invest[cur] = y[cur] < x[cur] ? y[cur] : max(y[cur], y[cur] - x[cur] + childInvest);
    return profit[cur];
}

int best_case(int root) {
    int cur;
    int money = 0, bestCost = 0;
    get_profit(root);
    pq.emplace(0, 0);
    do {
        cur = pq.top().second;
        pq.pop();
        bestCost = max(bestCost, y[cur] - money);
        money += x[cur] - y[cur];
        for (int u:G[cur])
            if (profit[u] > 0) pq.emplace(invest[u], u);
    } while (cur != motherlode);
    return bestCost;
}

void init() {
    cin >> n;
    p.resize(n);
    x.resize(n);
    y.resize(n);
    worst.resize(n);
    profit.resize(n);
    invest.resize(n);
    G.resize(n);
    for (int i = 1; i < n; i++) {
        cin >> p[i] >> x[i] >> y[i];
        G[p[i]].push_back(i);
        if (x[i] == -1) motherlode = i, x[i] = oo;
    }
    x[0] = 0, y[0] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    init();
    cout << worst_case(0) + 1 << ' ' << best_case(0) << endl;
    return 0;
}