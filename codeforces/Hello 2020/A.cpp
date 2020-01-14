#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, b % a);
}
int lcm(int a, int b){
    return a * b / gcd(a, b);
}
int main(){
    ios_base::sync_with_stdio(0);
    //freopen("Ain.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    string a[n + 1];
    string b[m + 1];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    int t;
    cin >> t;
    while(t--){
        int year;
        cin >> year;
        year--;
        int x = (year) % n;
        int y = (year) % m;
        cout << a[x] + b[y] << endl;
    }
    return 0;
}