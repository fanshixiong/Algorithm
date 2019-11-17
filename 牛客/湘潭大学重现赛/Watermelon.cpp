#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAX = 1e6+5;
int n, m, t;
int L, R;
int num[MAX];
bool Solve(){
	int i=0;
	while(1){
		/*
		if(i!=t){
			if(L<=0)
				return 0;
			L -= 1;
			R -= num[i];
		}
		else if(i==t){ //可能不满足R<=0的情况 
			if(R<=0)
				return 1;
			L -= num[i];
			R -= num[i];
		}*/
		if(i!=t && L<=0)
			return 0;
		if(i==t && R<=0)
			return 1;
		if(i!=t){
			L -= 1;
			R -= num[i];
		}
		else{
			L -= num[i];
			R -= num[i];
		}
		i++;
		if(i==n)
			i=0;
	}
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		int max=0;
		L=R=m;
		for(int i=0; i<n; i++){
			scanf("%d", &num[i]);
			if(max<num[i]){
				max=num[i];
				t=i;
			}
		}
		bool b= Solve();
		if(b)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
