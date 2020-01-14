#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
map<string, int> H1[maxn], H2[maxn];
vector<char> ans;
char get(string a, string b){
    int c[30];
    memset(c, 0, sizeof(c));
    for (int i = 0; i < a.size(); i++){
        c[a[i] - 'a']++;
    }
    for (int i = 0; i < b.size(); i++){
        c[b[i] - 'a']--;
    }
    for (int i = 0; i < 26; i ++){
        if(c[i]>0)
            return i + 'a';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if (n==1){
        string ss;
        cout << "? 1 1" << endl;
        cin >> ss;
        cout << "! " << ss << endl;
        return 0;
    }
    cout << "? 1 " << n << endl;
    for (int i = 0; i < n * (n + 1) / 2; i++){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        H1[s.size()][s]++;
    }
    cout << "? 2 " << n << endl;
    for (int i = 0; i < n * (n - 1) / 2; i++){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        H2[s.size()][s]++;
    }
    for (int i = 1; i <= n; i++){
        
        for(auto p:H2[i]){
            H1[i][p.first] -= H2[i][p.first];
        }

        for(auto p:H1[i]){
            if(p.second>0){
                string new1 = "";
                for (int j = 0; j < ans.size(); j++){
                    new1 += ans[j];
                }
                ans.push_back(get(p.first, new1));
            }
        }
    }
    string res = "";
    for (int j = 0; j < ans.size(); j++)
        res += ans[j];
    cout << "! " << res << endl;
    return 0;
}