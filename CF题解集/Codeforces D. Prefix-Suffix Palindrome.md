## Codeforces D. Prefix-Suffix Palindrome 

#### 题解：

和D1相同，区别是找中间的回文串要压缩时间，用到了马拉车算法。（算法介绍在下面：

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll maxlen, flg;
string Manacher(string s1){
    string s = "$#";
    for (int i = 0; i < s1.size(); i++){
        s += s1[i], s += '#';
    }
    vector<ll> p(s.size(), 0);
    ll c = 0, ra = 0;
    maxlen = 0; flg = 0;
    for (int i = 1; i < s.size(); i++){
        p[i] = ra > i + p[i] ? min(p[2 * c - i], ra - i) : 1;
        while(s[i+p[i]] == s[i-p[i]]) ++p[i];
        if(ra < i+p[i]){
            c = i; ra = i+p[i];
        }
        if(i == p[i] && maxlen < p[i]){
            maxlen = p[i] - 1; flg = 1;
        }
        if(i+p[i] == s.size() && maxlen < p[i]){
            maxlen = p[i] - 1, flg = 2;
        }
    }
    if(flg == 1)
        return s1.substr(0, maxlen);
    else{
        return s1.substr(s1.size() - maxlen);
    }
}
void solve(){
    string src; cin >> src;
    ll l = 0, r = src.size() - 1;
    while(l<r && src[l] == src[r]){l++, r--;}
    if(l >= r){
        cout << src << endl;
        return;
    }
    //cout << src.substr(l, r - l + 1) << "  ";
    string mid = Manacher(src.substr(l, r-l+1));
    //cout << mid << endl;
    cout << src.substr(0, l) + mid + src.substr(r+1) << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    ll t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```

















#### Manacher算法 思想

$ p[i]= r > i + p[i] ? min( p[2 * c - i] , r - i) : 1$
p[i]维护回文串的长度，r是预处理后的字符串中回文串能到达的最右端，c是到达最右端时的中点。

令 $i\_mirror = 2 * c - i$;
如图，很明显，当r大于当前遍历字符串i点+其回文长度时，此时可以发现 i 点和 i_mirror 点关于c对称，
因为c的回文右端到达r点，这时$p[i\_mirror]$ 是已经被计算的 。
假如 $r-i>=p[i\_mirror]$ 即 i到以c为中点的回文串最右端r比以$i\_mirror $为中心的回文串长度大，那么此时$p[i]$的值至少是$p[i\_mirror]$；
当$ r - i< p[i\_mirror]$ 时，此时以$i\_mirror$为中心的回文串长度比i到 i到以c为中点的回文串最右端r 大，那么关于中心点c 对称的$ p[i\_mirror]$部分值无法得到匹配（大于r部分），此时$p[i]$的值至少是$r-i$ 。

模板：

```cpp
string Manacher(string s1){
    string s = "$#";
    for (int i = 0; i < s1.size(); i++){  s += s1[i], s += '#'; }
    vector<int> p(s.size(), 0);
    int c = 0, r = 0, maxlen = 0, maxpoint = 0;
    for (int i = 1; i < s.size(); i++){
        p[i] = r > i + p[i] ? min(p[2 * c - i], r - i) : 1;  //见上述
        while(s[i+p[i]] == s[i-p[i]]) ++p[i];  //中心拓展算法
        if(r < i+p[i]){ c = i; r = i+p[i]; }
        if(maxlen < p[i]){ maxlen = p[i]; maxpoint = i;  }
    }
    return s1.substr((maxpoint - maxlen) / 2, maxlen - 1);
}
```

