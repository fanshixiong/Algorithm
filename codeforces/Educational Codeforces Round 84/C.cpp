#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i){
        int x, y; cin >> x >> y;
    }
    for(int i = 1; i <= k; ++i){
        int x, y; cin >> x >> y;
    }
    string s = "";
    s += string(n - 1, 'U');
    s += string(m - 1, 'L');
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            s += string(m - 1, 'R');
        }
        else {
            s += string(m - 1, 'L');
        }
        if (i < n)
            s += "D";
    }
    cout << s.size() << endl;
    cout << s << endl;
    return 0;
}