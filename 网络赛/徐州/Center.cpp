#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;
struct node{
	int x, y;
}point[maxn];
int n;
map<pair<int, int>, int> mmp;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		int xi, yi;
		scanf("%d%d", &xi, &yi);
		point[i].x=xi*2;
		point[i].y=yi*2;
	}
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int xt=(point[i].x+point[j].x)/2;
			int yt=(point[i].y+point[j].y)/2;
			mmp[{xt, yt}]++;
			cout << xt << "  " << yt << "  " << mmp[{xt, yt}] <<endl;
		}
	}
	int ans=n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int xt=(point[i].x+point[j].x)/2;
			int yt=(point[i].y+point[j].y)/2;
			ans = min(ans, n-2*mmp[{xt, yt}]);
		}
	}
	cout << ans <<endl;
	return 0;
} 
