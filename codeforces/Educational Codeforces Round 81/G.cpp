#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#define ALL(x) (x).begin(), (x).end()
#define sz(a) int(a.size())
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repd(i,x,n) for(int i=x;i<=n;i++)
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define gbtb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MSC0(X) memset((X), '\0', sizeof((X)))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define eps 1e-6
#define chu(x) cout<<"["<<#x<<" "<<(x)<<"]"<<endl
#define du3(a,b,c) scanf("%d %d %d",&(a),&(b),&(c))
#define du2(a,b) scanf("%d %d",&(a),&(b))
#define du1(a) scanf("%d",&(a));
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll powmod(ll a, ll b, ll MOD) { if (a == 0ll) {return 0ll;} a %= MOD; ll ans = 1; while (b) {if (b & 1) {ans = ans * a % MOD;} a = a * a % MOD; b >>= 1;} return ans;}
void Pv(const vector<int> &V) {int Len = sz(V); for (int i = 0; i < Len; ++i) {printf("%d", V[i] ); if (i != Len - 1) {printf(" ");} else {printf("\n");}}}
void Pvl(const vector<ll> &V) {int Len = sz(V); for (int i = 0; i < Len; ++i) {printf("%lld", V[i] ); if (i != Len - 1) {printf(" ");} else {printf("\n");}}}
inline long long readll() {long long tmp = 0, fh = 1; char c = getchar(); while (c < '0' || c > '9') {if (c == '-') fh = -1; c = getchar();} while (c >= '0' && c <= '9') tmp = tmp * 10 + c - 48, c = getchar(); return tmp * fh;}
inline int readint() {int tmp = 0, fh = 1; char c = getchar(); while (c < '0' || c > '9') {if (c == '-') fh = -1; c = getchar();} while (c >= '0' && c <= '9') tmp = tmp * 10 + c - 48, c = getchar(); return tmp * fh;}
const int maxn = 300010;
const int inf = 0x3f3f3f3f;
/*** TEMPLATE CODE * * STARTS HERE ***/
int n;
int p[maxn];
int id[maxn];
ll a[maxn];
ll sum[maxn];
struct node
{
    int l, r;
    ll laze;
    ll val;
} segment_tree[maxn << 2];
void pushup(int rt)
{
    segment_tree[rt].val = min(segment_tree[rt << 1].val, segment_tree[rt << 1 | 1].val);
}
void build(int rt, int l, int r)
{
    segment_tree[rt].l = l;
    segment_tree[rt].r = r;
    if (l == r)
    {
        segment_tree[rt].val = sum[l];
        segment_tree[rt].laze = 0ll;
        return ;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}
void pushdown(int rt)
{
    segment_tree[rt << 1 | 1].val += segment_tree[rt].laze;
    segment_tree[rt << 1 | 1].laze += segment_tree[rt].laze;
    segment_tree[rt << 1 ].val += segment_tree[rt].laze;
    segment_tree[rt << 1 ].laze += segment_tree[rt].laze;
    segment_tree[rt].laze = 0;
}
void update(int rt, int l, int r, int num)
{
    if (segment_tree[rt].laze && l != r)
    {
        pushdown(rt);
    }
    if (segment_tree[rt].l >= l && segment_tree[rt].r <= r)
    {
        segment_tree[rt].val += num;
        segment_tree[rt].laze += num;
        return ;
    }
    int mid = segment_tree[rt].l + segment_tree[rt].r >> 1;
    if (r > mid)
    {
        update(rt << 1 | 1, l, r, num);
    }
    if (l <= mid)
    {
        update(rt << 1, l, r, num);
    }
    pushup(rt);
}
int main()
{
    //freopen("D:\\code\\text\\input.txt","r",stdin);
    //freopen("D:\\code\\text\\output.txt","w",stdout);
    n = readint();
    repd(i, 1, n)
    {
        p[i] = readint();
        id[p[i]] = i;
    }
    repd(i, 1, n)
    {
        a[i] = readll();
    }
    repd(i, 1, n)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    ll ans = a[n];
    build(1, 1, n - 1);
    ans = min(ans, segment_tree[1].val);
    int x;
    repd(i, 1, n)
    {
        x = id[i];
        if (x != n)
        {
            update(1, x, n - 1, -a[x]);
        }
        if (x != 1)
        {
            update(1, 1, x - 1, a[x]);
        }
        ans = min(ans, segment_tree[1].val);
        //cout << ans << "   ";
    }
    printf("%lld\n", ans );


    return 0;
}
