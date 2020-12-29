/*
https://ac.nowcoder.com/discuss/580464?source_id=profile_create_nctrack&channel=-1
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[33];
void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    int cnt = 0, pos;
    for(int i = 0; i < n; i++){
    	if(a[i] & 1) cnt++, pos = i;
    }
    if(cnt >= 2) {
    	cout << 0 << endl;
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < a[i]; j++) cout << (char)('a' + i); 
    	}
    	cout << endl;
    	return ;
    }

    int gc = a[0];
    for(int i = 1; i < n; i++) gc = __gcd(gc, a[i]);

    cout << gc << endl;
    if(cnt < 1){
    	for(int i = 0; i < n; i++) a[i] /= gc, a[i] <<= 1;

    	gc >>= 1;
    	while(gc--){
    		for(int i = 0; i < n; i++){
    			for(int j = 0; j < a[i] / 2; j++) cout << (char)('a' + i);
    		}

    		for(int i = n-1; i >= 0; i--){
    			for(int j = 0; j < a[i] / 2; j++) cout << (char)('a' + i);
    		}	
    	}
    }
    else{
    	for(int i = 0; i < n; i++) a[i] /= gc;

    	while(gc--){
    		for(int i = 0; i < n; i++){
    			for(int j = 0; j < a[i] / 2; j++) cout << (char)('a' + i);
    		}
    		cout << (char)('a' + pos);
    		for(int i = n-1; i >= 0; i--){
    			for(int j = 0; j < a[i] / 2; j++) cout << (char)('a' + i);
    		}	
    	}
    }
    cout << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}