#include<iostream>
#include<vector> 
#include<cmath>
#include<algorithm>
using namespace std;
vector<vector<int> > Min(300, vector<int>(300));
vector<vector<int> > Max(300, vector<int>(300));
int main(){
	int N; cin >> N;
	vector<int> num(2*N+1);
	vector<int> sum(2*N+1);
	for(int i=1; i<=N+N; i++){
		if(i<=N){
			cin >> num[i];
			num[i+N]=num[i];
		}
		sum[i]=sum[i-1]+num[i];
	}
	for(int k=1; k<N; k++){
		for(int i=1, j=k+i; (i<2*N)&&(j<2*N); i++, j++){
			Min[i][j]=0x3f3f3f3f;
			for(int m=i; m<j; m++){
				Max[i][j]=max(Max[i][j], Max[i][m]+Max[m+1][j]+sum[j]-sum[i-1]);
				Min[i][j]=min(Min[i][j], Min[i][m]+Min[m+1][j]+sum[j]-sum[i-1]);
			}
		}	
	}
	int ans1, ans2=0x3f3f3f3f;
	for(int i=1; i<=N; i++){
		ans1=max(ans1, Max[i][i+N-1]);
		ans2=min(ans2, Min[i][i+N-1]);
	}
	cout << ans2 << endl << ans1 << endl;
	return 0;
}
