#include <bits/stdc++.h>
using namespace std;

inline int mypow(int n) { return n * n; }

int arr[1005];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int tot = 1 << 30;

    for(int i = 1; i < 84; i++) {
        int tmp = 0, l = i, r = i + 17;
        for(int j = 0; j < n; j++) { 
            if(arr[j] < l) tmp += mypow(arr[j] - l);
            else if(arr[j] > r) tmp += mypow(arr[j] - r);
        }
        tot = min(tot, tmp); 
    }
    cout << tot << endl;
    return 0;
}