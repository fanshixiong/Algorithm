#include<bits/stdc++.h>
using namespace std;
vector<int> a;
bool judge(int x){
	bool flg=1;
	while(x){
		if(x%3==2){
			flg=0;
			break;
		}
		x/=3;
	}
	if(flg)
		return 1;
	return 0;
}
void solve(){
	for(int i=1; i<=19683; i++){
		if(judge(i))
			a.push_back(i);
	}
}
int main(){
	ios::sync_with_stdio(0);
	solve();
	int q;
	cin >> q;
	while(q--){
		int x;
		cin >> x;
		int pos = lower_bound(a.begin(), a.end(), x)-a.begin();
		cout << a[pos] << endl;
	}
	return 0;
}
