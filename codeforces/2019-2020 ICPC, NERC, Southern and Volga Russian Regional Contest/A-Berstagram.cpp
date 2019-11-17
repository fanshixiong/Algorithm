#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
struct node{
	int mina, maxa;
}num[maxn];
int pos[maxn];
int a[maxn];

int main(){
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		num[i].maxa=i;
		num[i].mina=i;
		pos[i]=i;
		a[i]=i;
	}
	for(int i=0; i<m; i++){
		int x;
		cin >> x;
		if(pos[x] > 1){
			int tp=a[pos[x]-1];
			pos[tp]++;
			num[tp].maxa = max(pos[tp], num[tp].maxa);
			pos[x]--;
			num[x].mina = min(num[x].mina, pos[x]);
			swap(a[pos[tp]], a[pos[x]]);
		}
	}
	for(int i=1; i<=n; i++){
		cout << num[i].mina << " " << num[i].maxa << endl;
	}
	return 0;
} 
