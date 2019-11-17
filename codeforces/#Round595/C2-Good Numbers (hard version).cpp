//https://codeforces.com/blog/entry/70779?locale=en
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	int q;
	cin >> q;
	while(q--){
		ll n;
		cin >> n;
		vector<int> val;
		int pos2=-1;
		while(n>0){
			val.push_back(n%3);
			if(n%3==2)
				pos2 = val.size()-1;
			n/=3;
		}
		val.push_back(0);
		if(pos2 != -1){
			int pos0 =find(val.begin()+pos2, val.end(), 0) - val.begin();
			val[pos0]=1;
			for(int i=pos0-1; i>=0; i--)
				val[i]=0;
		}
		ll ans=0;
		ll pw=1;
		for(int i=0; i<val.size(); i++){
			ans += pw*val[i];
			pw*=3;
		}
		if(val.back()==1) 
			ans = pw/3;
		cout << ans << endl;
	}
	
	return 0;
}
