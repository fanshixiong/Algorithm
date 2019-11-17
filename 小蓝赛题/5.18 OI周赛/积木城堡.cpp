#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int nx;
	int sum;
	int num[105];
};
vector<node> cas(105);
bool cmp(node &a, node &b){
	return a.sum < b.sum;
}
int main(){
	int n; cin >> n;
	for(int i=0; i<n; i++){
		int s=0, x, k=0;;
		cin >> x;
		while(x!=-1){
			cas[i].num[k++]=x;
			cas[i].sum+=x;
			cin >> x;
		}
		cas[i].nx=k;
	}
	sort(cas.begin(), cas.end(), cmp);
	int ans=0x3f3f3f;
	for(int i=0; i<n; i++){
		ans=cas[i].sum;
		vector<int> dp(102);
		for(int k=0; k<cas[i].nx; k++){
			for(int j=ans; j>=0; j--){
				if(j-cas[i].num[i]>0){
					dp[j]=max(dp[j], dp[j-cas[i].num[i]]+cas[i].num[i]);
				}
			}
		}
		ans = min(ans, dp[ans]);
	}
	cout << ans << endl;
	return 0;
} 
