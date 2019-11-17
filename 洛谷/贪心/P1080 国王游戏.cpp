#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int sum[5000047]={1};
int ans[500047]={1};
int cuti[500047]={0};
int lena=0, len_t=0, len=1;
struct node{
	long long left, right;
};
bool cmp(node &a, node &b){
	return a.left*a.right < b.left*b.right;
}
void mut(long long x){
	for(int i=0; i<len; i++){
		sum[i]*=x;
	}
	int tmp=0;
	for(int i=0; i<len; i++){
		tmp += sum[i];
		sum[i]=tmp%10;
		tmp /= 10;
	}
	while(tmp){
		sum[len]=tmp%10;
		tmp/=10;
		len++;
	}
	/*
	cout << "MUTI:" << endl;
	for(int i=0; i<len; i++)
		cout << sum[i];
	cout << endl;
	*/
}
void cut(long long x){
	int tmp=0;
	len_t=len;
	for(int i=len_t-1; i>=0; i--){
		tmp=tmp*10+sum[i]; 
		cuti[i]=tmp/x;
		tmp%=x;
	}
	while(!cuti[len_t-1]){
		len_t--;
	}
	/*
	cout << "CUT:" << endl;
	for(int i=0; i<len_t; i++)
		cout << cuti[i];
	cout << endl;
	*/
}
void max(int t){
	if(lena>len_t) return;
	int b=0;
	if(lena<len_t){
		for(int i=0; i<len_t; i++)
			ans[i]=cuti[i];
		lena=len_t;
	}
	else{
		for(int i=0; i<lena; i++){
			if(ans[i] < cuti[i]){
				b=1;
				break;
			}
		}
		if(b){
			for(int i=0; i<len_t; i++)
				ans[i]=cuti[i];
			lena=len_t;
		}
	}
}
int main(){
	int n;
	cin >> n;
	vector<node> num(n+1);
	for(int i=0; i<=n; i++)
		cin >> num[i].left >> num[i].right;
	sort(num.begin()+1, num.end(), cmp);
	for(int i=1; i<=n; i++){
		mut(num[i-1].left);
		cut(num[i].right);
		max(i);
	}
	for(int i=lena-1; i>=0; i--){
		cout << ans[i];
	}
	cout << endl;
	return 0;
} 
