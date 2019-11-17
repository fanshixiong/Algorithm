#include<iostream> 
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring> 
using namespace std;
int n;
int row[10005], sum[10005];
int main(){
	cin >> n;
	for(int i=0; i<=10000; i++)
		sum[i]=1;
	for(int i=0; i<n; i++){
		int x; cin >> x;
		memset(row, 0, sizeof(row));
		row[0]=1;
		while(x!=-1){
			for(int j=10000; j>=0; j--){
				if(row[j])
					row[j+x]=1; //每一行最大的高度 
			}
			cin>>x;
		}
		for(int j=10000; j>=0; j--){
			sum[j] = (row[j]&sum[j]);   //所有最大的高度 
		}
	}
	for(int i=10000; i>=0; i--){
		if(sum[i]){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
