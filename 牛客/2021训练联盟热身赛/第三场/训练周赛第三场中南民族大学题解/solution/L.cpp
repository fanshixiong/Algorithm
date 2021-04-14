#include <bits/stdc++.h>
#pragma GCC optiMinze(2)
using namespace std;
#define iny long long
const iny maxn = 1e5 + 10;
struct node
{
    int Max;
    int Min;
    int _Max;
    node(){
        Max=Min=_Max=0;
    }
};
node tree[15][maxn << 2];
int v[15][maxn], d[maxn], n, q, s;

inline void push_up(iny p)
{
    tree[s][p]._Max = max(tree[s][2 * p]._Max, max(tree[s][2 * p + 1]._Max, tree[s][2 * p + 1].Max - tree[s][2 * p].Min));
    tree[s][p].Max = max(tree[s][2 * p].Max, tree[s][2 * p + 1].Max);
    tree[s][p].Min = min(tree[s][2 * p].Min, tree[s][2 * p + 1].Min);
}

void build(iny p, iny l, iny r)
{
    if (l == r)
    {
        tree[s][p]._Max = 0;
        tree[s][p].Max = v[s][l];
        tree[s][p].Min = v[s][l];
        return;
    }
    iny Mind = l + r >> 1;
    build(p << 1, l, Mind);
    build((p << 1) + 1, Mind + 1, r);
    push_up(p);
}

node query(iny l, iny r, iny p, iny pl, iny pr)
{
    if (l <= pl && r >= pr)
    {
        return tree[s][p];
    }
    iny Mind = pl + pr >> 1;
    node ans1, ans2, ans3;
    if (l <= Mind)
    {
        ans2 = query(l, r, p << 1, pl, Mind);
        ans1 = ans2;
    }
    if (r > Mind)
    {
        ans3 = query(l, r, (p << 1) + 1, Mind + 1, pr);
        if (l <= Mind)
        {
            ans1._Max = max(ans3.Max - ans2.Min, max(ans3._Max, ans2._Max));
            ans1.Min = min(ans2.Min, ans3.Min);
            ans1.Max = max(ans2.Max, ans3.Max);
        }
        else
            ans1 = ans3;
    }
    return ans1;
}

int main()
{
    scanf("%d",&n);
    for (iny i = 1; i <= n; i++)
    {
        scanf("%d%d", &v[0][i], &d[i]);
    }
    for (iny i = 0; i <= 6; i++)
    {
        iny nw = i;
        for (iny j = 1; j <= n; j++)
        {
            if (nw == 0 || nw == 6)
            {
                v[i + 1][j] = v[0][j];
            }
            if (nw == 1 || nw == 5)
            {
                v[i + 1][j] = v[0][j] + d[j];
            }
            if (nw == 2 || nw == 4)
            {
                v[i + 1][j] = v[0][j] + 2 * d[j];
            }
            if (nw == 3)
            {
                v[i + 1][j] = v[0][j] + 3 * d[j];
            }
            nw++;
            nw %= 7;
        }
    }
    for (s = 1; s <= 7; s++)
        build(1, 1, n);
    for (iny i = 1; i <= n / 2; i++)
    {
        swap(v[0][i], v[0][n - i + 1]);
        swap(d[i], d[n - i + 1]);
    }
    for (iny i = 0; i <= 6; i++)
    {
        iny nw = i;
        for (iny j = 1; j <= n; j++)
        {
            if (nw == 0 || nw == 6)
            {
                v[i + 8][j] = v[0][j];
            }
            if (nw == 1 || nw == 5)
            {
                v[i + 8][j] = v[0][j] + d[j];
            }
            if (nw == 2 || nw == 4)
            {
                v[i + 8][j] = v[0][j] + 2 * d[j];
            }
            if (nw == 3)
            {
                v[i + 8][j] = v[0][j] + 3 * d[j];
            }
            nw++;
            nw %= 7;
        }
    }
    for (s = 8; s <= 14; s++)
        build(1, 1, n);
    scanf("%d", &q);
    while (q--)
    {
        iny l, r;
        cin >> l >> r;
        if (l <= r)
        {
            s = (700000 + 2 - l) % 7;
            if (s == 0)
                s = 7;
        }
        else
        {
            s = (700000 + l - n + 1) % 7;
            if (s == 0)
                s = 7;
            s += 7;
            l = n - l + 1;
            r = n - r + 1;
        }
        node ans = query(l, r, 1, 1, n);
        printf("%d\n", ans._Max);
    }
    return 0;
}