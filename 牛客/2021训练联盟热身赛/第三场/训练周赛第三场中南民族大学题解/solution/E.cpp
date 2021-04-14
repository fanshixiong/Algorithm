#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5, maxm = maxn * 3;

int vowNum[maxn], len[maxn];
char newWord[maxn];
string wd[maxn];


int trie[maxm][26], idx[maxm], fail[maxm];
int tot = 0, last[maxm];

void insert(char *nw, int id, int lenw) {
    int p = 0;
    for (int i = 0; i < lenw; i++) {
        int c = nw[i] - 'A';
        if (!trie[p][c])
            trie[p][c] = ++tot;
        p = trie[p][c];
    }
    if (vowNum[id] >= vowNum[idx[p]])
        idx[p] = id;
}

void getNewWord(string word, int id) {
    int lenw = 0;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U')
            vowNum[id]++;
        else
            newWord[lenw++] = word[i];
    }
    newWord[lenw] = '\0';

    len[id] = lenw;
    insert(newWord, id, lenw);
    //cout<<newWord<<" nw"<<endl;
}

int Q[maxm];

void build() {
    int t = 0, h = 1;
    for (int i = 0; i < 26; i++) {
        if (trie[0][i])
            Q[++t] = trie[0][i];
    }
    while (h <= t) {
        //cout<<1<<endl;
        int u = Q[h++];
        for (int i = 0; i < 26; i++) {
            if (trie[u][i]) {
                fail[trie[u][i]] = trie[fail[u]][i];
                Q[++t] = trie[u][i];
            } else
                trie[u][i] = trie[fail[u]][i];
        }
        last[u] = idx[fail[u]] ? fail[u] : last[fail[u]];
    }
}

char str[maxm];
int dp[maxm];
int pre[maxm], ans[maxm];

void sovle() {
    int p = 0;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    int lens = strlen(str + 1);
    for (int i = 1; i <= lens; i++) {
        int c = str[i] - 'A';
        p = trie[p][c];
        for (int j = p; j; j = last[j]) {
            if (idx[j]) {
                int x = dp[i - len[idx[j]]];
                if (x != -1 && dp[i] < x + vowNum[idx[j]]) {
                    pre[i] = i - len[idx[j]], ans[i] = idx[j];
                    dp[i] = x + vowNum[idx[j]];
                }
            }
        }
    }
    vector<int> V;
    for (int i = lens; i; i = pre[i])
        V.push_back(ans[i]);
    for (int i = V.size() - 1; i > 0; i--)
        cout << wd[V[i]] << ' ';
    cout << wd[V[0]] << '\n';
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> wd[i];
        getNewWord(wd[i], i);
    }
    build();
    cin >> str + 1;
    sovle();
    return 0;
}