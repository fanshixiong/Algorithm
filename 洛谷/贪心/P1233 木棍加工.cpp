#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct node{
	int length, width;
};
bool cmp1(node &a, node &b){
	return a.length>b.length;
}
bool cmp2(node &a, node &b){
	return a.width>b.width;
}
int main(){
	int n; cin >> n;
	vector<node> club(n+1);
	for(int i=0; i<n; i++){
		cin >> club[i].length >> club[i].width;
	}
	sort(club.begin(), club.end(), cmp1);
	int ans1=1, ans2=1;
	
	vector<int> vis(n+1);
	for(int i=0; i<n; i++){
		node tmp=club[i];
		if(!vis[i]){
			int j=i;
			while(j<n){
				if(tmp.length>=club[j].length && tmp.width>=club[j].width && !vis[j]){
					tmp=club[j];
					vis[j]=1;
					//cout << j << endl;
				}
				j++;
			}
			ans1++;
		}
	}
	sort(club.begin(), club.end(), cmp2);
	for(int i=0; i<n; i++)
		vis[i]=0;
	for(int i=0; i<n; i++){
		node tmp=club[i];
		if(!vis[i]){
			int j=i;
			while(j<n){
				if(tmp.length>=club[j].length && tmp.width>=club[j].width && !vis[j]){
					tmp=club[j];
					vis[j]=1;
				//	cout << j << endl;
				}
				j++;
			}
			ans2++;
		}
	}
	cout << min(ans1, ans2)-1 << endl;
	return 0;
} 
