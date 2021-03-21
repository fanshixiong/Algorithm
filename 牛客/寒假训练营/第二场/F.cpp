#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
int a[maxn];
/*void solve(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];

	// int p = -1;
	// for(int i = 1; i <= n; i++) if(a[i] == 1) { p = i; break; }

	// int k = p;
	// reverse(a + 1, a + k + 1);
	//for(int i = 1; i <= n; i++) cout << a[i] << " ";
	int i = 1, k = -1;
	while(i <= n){
		if(a[i] == i) {i++; continue;}
		if(k == -1){
			for(int j = i; j <= n; j++) if(i == a[j]) { k = j-i+1; break;}
		}
		if(a[k+i-1] == i){
			//cout << i << " " << i + k - 1 << endl;
			reverse(a+i, a+i+k);
			// for(int i = 1; i <= n; i++) cout << a[i] << " ";
			i++;
		}
		else{
			cout << "no" << endl;
			return;
		}
	}
	cout << "yes" << endl << (k == -1 ? 1 : k) << endl;
}*/
void solve(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	cout << "yes" << endl;
	for(int i = n; i >= 1; i--) if(a[i] != i)  {cout << abs(a[i]-i)+1 << endl; return;}

	cout << 1 << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}