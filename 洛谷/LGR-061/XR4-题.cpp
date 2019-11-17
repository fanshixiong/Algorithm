/*
#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull a,b;
map<pair<ull, ull>, ull> mp;
int main(){
	cin>> a>>b;
	ull cnt=0;
	if(a*a==4*b){
	 	cout << "inf" << endl;
	 	return 0;
	}
	for(ull i=0; i<100000000; i++){
		ull res = i*i+a*i+b;
		ull tmp=sqrt(res);
		if(tmp*tmp == res && !mp[{i, tmp}]){
			cnt++;
			mp[{i, tmp}]++;
			//cout << i << " " << tmp << " " << mp[{i, tmp}] << endl;
		}
	}
	cout << cnt << endl;
	return 0;
}
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a,b;
ll ans;

int main(){
    cin>>a>>b;
    
    ll tp=sqrt(b);s
    for(ll i=0;i<=max(a/2,tp);i++){
        ll temp1=b-i*i;
        ll temp2=2*i-a;
        if(temp1==temp2&&temp1==0){
            puts("inf");
            return 0;
        }
        if(temp2==0) continue;
        if(temp1/temp2<0) continue;
        if(temp1%temp2!=0) continue;
        ans++;
    } 
    cout<<ans;
    return 0;
}
