#include<bits/stdc++.h>
using namespace std;

sunordered_map<int, int> mmp;
int find(int x){
	if(!mmp.count(x))
		return x;
	return mmp[x] = find(mmp[x]);
}
int main(){
	std::ios::sync_with_stdio(0);cin.tie(0);
	int n, q;
	scanf("%d%d", &n, &q); 
	int op, x;
	for(int i=1; i<=q; i++){
		scanf("%d%d", &op, &x);
		if(op == 1)
			mmp[x] = find(x+1);
		else{
			int ans = find(x);
			printf("%d\n", ans > n ? -1 : ans);
		}
	}
	return 0;
}
