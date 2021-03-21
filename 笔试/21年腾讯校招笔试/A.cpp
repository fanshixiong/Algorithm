#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
vector<int> a[maxn];
int b[maxn];
void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int m; cin >> m;
		for(int j = 0; j < m; j++) {
			int x; cin >> x;
			a[i].emplace_back(x);
		}
		//sort(a[i].begin(), a[i].end());
	}

	int q; cin >> q;
	while(q--){
		int p; cin >> p;
		for(int i = 0; i < p; i++) cin >> b[i];
		int k; cin >> k;
		priority_queue<int, vector<int>, greater<int> > q;

		for(int i = 0; i < p; i++){
			for(auto c : a[b[i]-1]) {
				//cout << c << " fs ";
                q.push(c);
            }
		}
		k --;
		while(k-- > 0) q.pop(); 
		cout << q.top() << endl;
	}	
}

int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}