## codeforces Hello 2020 D. New Year and Conference

---

（还没理解）

#### 题意：

Filled with optimism, Hyunuk will host a conference about how great this new year will be!

The conference will have $n$ lectures. Hyunuk has two candidate venues $a$ and $b$. For each of the $n$ lectures, the speaker specified two time intervals $[sai,eai] (sai≤eai)$ and $[sbi,ebi] (sbi≤ebi)$. If the conference is situated in venue $a$, the lecture will be held from $sai$ to $eai$, and if the conference is situated in venue $b$, the lecture will be held from $sbi$ to $ebi$. Hyunuk will choose one of these venues and **all** lectures will be held at that venue.

Two lectures are said to overlap if they share any point in time in common. Formally, a lecture held in interval $[x,y]$ overlaps with a lecture held in interval $[u,v]$ if and only if $max(x,u)≤min(y,v)$.

We say that a participant can *attend* a subset $s$ of the lectures if the lectures in $s$ do not pairwise overlap ($i.e. $no two lectures overlap). Note that the possibility of attending may depend on whether Hyunuk selected venue $a$ or venue $b$ to hold the conference.

A subset of lectures $s$ is said to be *venue-sensitive* if, for one of the venues, the participant can attend $s$, but for the other venue, the participant cannot attend $s$.

A venue-sensitive set is problematic for a participant who is interested in attending the lectures in $s$ because the participant cannot be sure whether the lecture times will overlap. Hyunuk will be happy if and only if there are no venue-sensitive sets. Determine whether Hyunuk will be happy.

Input

The first line contains an integer $n$  ($1≤n≤100000$), the number of lectures held in the conference.

Each of the next $n$  lines contains four integers $sai, eai , sbi , ebi(1≤sai,eai,sbi,ebi≤109 , sai≤eai,sbi≤ebi).$

Output

Print "YES" if Hyunuk will be happy. Print "NO" otherwise.

You can print each letter in any case (upper or lower).

Examples

input

```
2
1 2 3 6
3 4 7 8
```

output

```
YES
```

input

```
3
1 3 2 4
4 5 6 7
3 4 5 5
```

output

```
NO
```

input

```
6
1 5 2 9
2 4 5 8
3 6 7 11
7 10 12 16
8 11 13 17
9 12 14 18
```

output

```
YES
```

Note

In second example, lecture set ${1,3}$ is venue-sensitive. Because participant can't attend this lectures in venue $a$, but can attend in venue $b$.

In first and third example, venue-sensitive set does not exist.



---

#### 题意：

有$2n$个区间，分别为$[sa1,ea1],[sb1,eb1],[sa2,ea2],[sb2,eb2],⋯,[san,ean],[sbn,ebn][sa1,ea1],[sb1,eb1],[sa2,ea2],[sb2,eb2],⋯,[san,ean],[sbn,ebn]$，每两个区间为一对，共$n$对区间。一对中的两个区间绑定在一起，从$n$对中选出一个子集。存在一种情况是：子集中某个系列（$a$或$b$）区间有区间交，而另外一个系列的区间没有区间交。如果这个情况发生在某个子集中，则输出NO,否则输出YES



---

#### 思路：

先考虑$a$系列区间交的所有可能，枚举交点，将包含该交点的所有$a$区间都放到数轴上，同时把对应的$b$区间也放在数轴上，那么这些$b$区间中两两之间也必须在某点交。



```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 4e5 + 10;
const int inf = 0x3f3f3f3f;
int n;
struct SegTree{
    int l, r;
    int mx, lazy;
} t[maxn * 4];
struct node{
    int l, r, id;
} a[maxn], b[maxn];
vector<int> l[maxn], r[maxn], alls;

void build(int p, int l, int r){
    t[p].l = l;
    t[p].r = r;
    if(l == r){
        t[p].mx = t[p].lazy = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    t[p].mx = t[p].lazy = 0;
}

void pushdown(int p){
    if(t[p].lazy){
        t[p << 1].mx += t[p].lazy;
        t[p << 1 | 1].mx += t[p].lazy;
        t[p << 1].lazy += t[p].lazy;
        t[p << 1 | 1].lazy += t[p].lazy;
        t[p].lazy = 0;
    }
}

int ask(int p, int l, int r){
    if(t[p].l >= l && t[p].r <= r){
        return t[p].mx;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    int res = 0;
    if(mid >= l)
        res = max(res, ask(p << 1, l, r));
    if(mid<r)
        res = max(res, ask(p << 1 | 1, l, r));
    return res;
}

void add(int p, int l, int r, int val){
    if(t[p].l >= l && t[p].r <= r){
        t[p].mx += val;
        t[p].lazy += val;
        return;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    if(mid >= l)
        add(p << 1, l, r, val);
    if(mid<r)
        add(p << 1 | 1, l, r, val);
    t[p].mx = max(t[p << 1].mx, t[p << 1 | 1].mx);
}

bool check(node *a, node *b){
    int len = alls.size();
    build(1, 1, len);
    for (int i = 1; i <= len; i++){
        l[i].clear();
        r[i].clear();
    }
    for (int i = 1; i <= n; i++){
        l[a[i].l].push_back(i);
        r[a[i].r].push_back(i);
    }

    int sz = 0;
    for (int i = 1; i <= len; i++){
        for (int j = 0; j < l[i].size(); j++){
            int id = l[i][j];

            int L = b[id].l, R = b[id].r;

            int res = ask(1, L, R);
            if(res != sz)
                return false;
            add(1, L, R, 1);
            sz++;
        }
        for (int j = 0; j < r[i].size(); j++){
            int id = r[i][j];
            int L = b[id].l, R = b[id].r;
            add(1, L, R, -1);
            sz--;
        }
    }
    return true;
}

int getId(int x){
    return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].l >> a[i].r >> b[i].l >> b[i].r;
        alls.push_back(a[i].l);
        alls.push_back(a[i].r);
        alls.push_back(b[i].l);
        alls.push_back(b[i].r);
        a[i].id = i;
        b[i].id = i;
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for (int i = 1; i<=n; i++){
        a[i].l = getId(a[i].l);
        a[i].r = getId(a[i].r);
        b[i].l = getId(b[i].l);
        b[i].r = getId(b[i].r);
    }
    int c1 = check(a, b);
    int c2 = check(b, a);
    if(c1 && c2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
```

