#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ll n, m;
    cin >> n >> m;
    ll g = gcd(n, m);
    n /= g, m /= g;
    if ((n & 1) && (m & 1))
        cout << g << endl;
    else 
        cout << "0" << endl;
    return 0;
}
