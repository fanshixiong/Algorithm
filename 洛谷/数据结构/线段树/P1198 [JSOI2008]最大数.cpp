#include<iostream>
using namespace std;
long long num[800005];
long long m, d;
void add(int s, int k, int o, int l, int r){
	if(l==r){
		num[o]=k;
		return;
	}
	int mid = (r-l)/2+l;
	if(mid >= s){
		add(s, k, o<<1, l, mid);
	}
	if(mid<s)
		add(s, k, o<<1|1, mid+1, r);
	num[o] = max(num[o<<1], num[o<<1|1])%d;
}
long long MAX(int x, int y, int o, int l, int r){
	if(x <= l && y >= r) 
		return num[o];
	int mid = (r-l)/2+l;
	long long a=-0x3f3f3f3f, b=-0x3f3f3f3f;
	if(mid >= x)
		a=MAX(x, y, o<<1, l, mid);
	if(mid < y)
		b=MAX(x, y, o<<1|1, mid+1, r);
	return max(a, b);
}
int main(){
	cin >> m >> d;
	string c;
	long long x, t=m;
	long long tmp=0, cnt=0;
	while(m--){
		cin >> c >> x;
		if (c[0] == 'A'){
			add(cnt+1, (x+tmp)%d, 1, 1, t);
			cnt++;
		}
		else if(c[0] == 'Q'){
			if(x==0) tmp=0;
			else 
				tmp=MAX(cnt-x+1, cnt, 1, 1, t)%d;
			cout << tmp << endl;
		}
	}
	return 0;
}
