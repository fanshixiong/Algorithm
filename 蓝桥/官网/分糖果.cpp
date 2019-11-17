#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int n;
vector<int> num(202);
int main(){
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> num[i];
	int ans=0;
	vector<int> vis(10002);
	vector<int> grid(n+2);
	for(int i=1; i<=n; i++){
		grid[i] = num[i]; 
		vis[num[i]]++;
	}
	while(vis[num[1]]!=n){
		for(int i=1; i<1002; i++)
			vis[i]=0;
		for(int i=2; i<=n; i++){
			grid[i-1]-=num[i-1]/2;
			grid[i]+=num[i-1]/2;
		}
		grid[n]-=num[n]/2;
		grid[1]+=num[n]/2;
		for(int i=1; i<=n; i++){
			if(grid[i]%2!=0){
				ans++;
				grid[i]++;
			}
			num[i]=grid[i];
			vis[num[i]]++;
		}
	}
	cout << ans << endl;
	return 0;
} 
