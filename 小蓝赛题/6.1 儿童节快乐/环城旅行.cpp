#include <iostream>
#include<cstring>
using namespace std;
int vis[500005];
int main(){
	int n, L;
	cin >> n >> L;
	if(n==1){
		cout << 1 << endl;
		return 0;
	}
	int x, y;
	cin >> y;
	//cin >> x >> y;
	int patrol=y, sum=0;;
	memset(vis, 0, sizeof(vis));
	for(int i=2; i<=n; i++){
		cin >> x >> y;
		/*
		if(patrol < x){
			vis[i-1]=0;
			patrol = y;
		}
		else 
			patrol += x-y;
		*/
		vis[i] = vis[i-1] + x-y;
		patrol = min(vis[i], patrol);
		//sum += x;
	}
	y = L-sum;
	/*
	if(patrol < y)
		vis[n]=0;
	*/
	for(int i=1; i<=n; i++){
		if(vis[i] == patrol)
			cout << i << " ";
	}
	cout << endl;
	return 0;
}
