#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;
int a[maxn], b[maxn];
void solve(){
    int n;
    string s;
    cin >> n >> s;
    int m = n;
    for (int i = 0; i<n; i++){
        int len = 0;
        while(i<n && s[i]=='<'){
            i++;
            len++;
        }
        for (int j = i; j>=i-len; j--){
            a[j] = m;
            m--;
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    m = 1;
    for (int i = 0; i<n; i++){
        int len = 0;
        while(i<n && s[i]=='>'){
            i++;
            len++;
        }
        for (int j = i; j>=i-len; j--){
            b[j]= m;
            m++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}