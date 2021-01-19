#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    int v1 = 1e5, v2 = -1;
    cin >> n >> m;
    unordered_set<int> S;
    while (n--) {
        int x;
        cin >> x;
        int y = m - x; 
        if (S.count(y)) {
            S.insert(x);
            if (x > y) swap(x, y);
            if (x < v1) v1 = x, v2 = y; 
        }
        else S.insert(x);
    }
    if (v1 < 1e5)  cout << v1 << " " << v2;
    else cout << "No Solution";
}