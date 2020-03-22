#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
int a[maxn], b[maxn], x[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    a[0] = b[0]; x[0] = 0;
    for (int i = 1; i < n; i++){
        x[i] = max(0, max(a[i - 1], x[i-1]));
        a[i] = b[i] + x[i];
    }
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}