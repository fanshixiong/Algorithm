#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
ll a[maxn];
ll h, n;
void solve(){
    cin >> h >> n;
    ll sums = 0, minn = 0, t = 0;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	sums += a[i];
    	minn = min(minn, sums);
    	h += a[i];
    	if(h <= 0 && !t) t = i+1;
    }
    if(t){
    	cout << t << endl;
    	return;
    }
    if(sums >= 0){
    	cout << -1 << endl;
    	return;
    }

    t = n;
    sums *= -1;
    // 减去最小值，防止减过头了，提前小于0
    ll time = (h + minn) / sums;
    cout << time << " " << sums << endl;
    t += n * time;
    h -= sums * time;
    cout << t << " " << h << endl; 
    while(h > 0){
    	for(int i = 0; i < n; i++){
    		t++;
    		h += a[i];
    		if(h <= 0) {
    			cout << t << endl;
    			return;
    		}
    	}
    }
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}