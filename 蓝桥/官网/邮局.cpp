#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n, m, k;
struct node{
	int x, y;
};
vector<node> vil_pos(55);
vector<node> post_pos(30);
vector<vector<double> > dist(55, vector<double>(30));
vector<int> post(30), best_post(30);
double dis, best=9999999.9;
double returnDist(){
	double ans=0;
	for(int i=0; i<n; i++){
		double tmp=99999.9;
		for(int j=0; j<m; j++)
			if(post[j])
				tmp = min(dist[i][j], tmp);
		//cout << tmp << " ";
		if(tmp!=99999.9)	
			ans += tmp;
	}
	//cout << ans << endl;
	return ans;
}
void dfs(int posts, int cnt){
	if(cnt>k || posts>=m) return;
	if(cnt == k){ //cout << returnDist() << endl;
		if(returnDist()<=best){ 
			for(int i=0; i<m; i++){
				best_post[i]=0;
				best_post[i]=post[i];
				//if(post[i])
					//cout << i << " ";
			}
			//cout << endl;
			best=returnDist();
		}
		return;
	}
	if(k-cnt>m-posts)
		return;
	double bef=returnDist();
	post[posts]=1;
	double aft=returnDist();
	dfs(posts+1, cnt+1);
	post[posts]=0;
	dfs(posts+1, cnt);
}
int main(){
	cin >> n >>m >> k;
	for(int i=0; i<n; i++)
		cin >> vil_pos[i].x >> vil_pos[i].y;
	for(int i=0; i<m; i++)
		cin >> post_pos[i].x >> post_pos[i].y;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			dist[i][j]=sqrt((vil_pos[i].x-post_pos[j].x)*(vil_pos[i].x-post_pos[j].x)+(vil_pos[i].y-post_pos[j].y)*(vil_pos[i].y-post_pos[j].y));
		}
	}
	dfs(0, 0); //vilage post 
	for(int i=0; i<m; i++){
		if(best_post[i])
			cout << i+1 << " ";
	} 
	cout << endl;
	return 0;
} 
