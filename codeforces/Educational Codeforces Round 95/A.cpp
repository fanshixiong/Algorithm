#include <bits/stdc++.h>
#define ll long long
using namespace std;

int K;
map<ll, int> vis;

ll Sieve(ll n){
	// 统计素数和
	ll sum = 0;
	ll m = (int)sqrt(n + 0.5);
	// 把不大于 根n 的所有素数的倍数剔除，剩下的就是素数
	for (ll i = 2; i <= m; i++){
		// 如过vis为0可执行，为1不可执行
		if (!vis[i]){
			// cout << vis[i] << " " << endl;
			// 将i的所有倍数置为1
			for (ll j = i * i; j <= n; j += i) vis[j] = true;
            sum = (sum + i) % K;
        }
    }
	for (ll i = m + 1; i <= n; i++) if (!vis[i]) sum += i;
	return sum;
}

/*
bool isPrime(long long k) {
    for (int i = 2; i <= sqrt(k) + 1; i++)
        if (k % i == 0) return false;
    return true;
}
*/

int main() {
    ll T, n, ans;

    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> n >> K;
        if (n == 1) {
            ans = 0 % K;
            cout << ans << endl;
            continue;
        }
        if (n == 2) {
            ans = 6 % K;
            cout << ans << endl;
            continue;
        }
        if (n == 3) {
            ans = 10 % K;
            cout << ans << endl;
            continue;
        }
        ans = 10 + (((5 + n + 1) % K) * ((n - 4 + 1) % K) / 2) % K;

        ll sum = Sieve(n + 1) - 5;
        ans = (sum + ans) % K;
        /*
        for (int i = 4; i <= n; ++i)
            if (isPrime(i + 1))
                ans = (ans + i + 1) % K;
        */
        cout << ans << endl;
    }

    return 0;
}