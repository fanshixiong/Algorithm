#include<bits/stdc++.h>
using namespace std;
int n,l,r,u,d,i;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
	string ans;
	while(n--){
		l=0;
		r=0;
		d=0;
		u=0;
        string a;
		cin >> a;
		for(auto b:a)
			switch(b){
				case 'L':l++;break;
				case 'R':r++;break;
				case 'D':d++;break;
				case 'U':u++;break;
			}
		l=min(l,r);
		d=min(d,u);
		if(l==0||d==0){
			l=min(l,1);
			d=min(d,1);
		}
		ans="";
		for(i=0;i<l;i++)
			ans+='L';
		for(i=0;i<d;i++)
			ans+='D';
		for(i=0;i<l;i++)
			ans+='R';
		for(i=0;i<d;i++)
			ans+='U';
		cout<<ans.length()<<endl<<ans<<endl;
	}
} 
