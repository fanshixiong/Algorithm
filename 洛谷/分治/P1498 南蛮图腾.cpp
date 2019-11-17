#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<vector<char> > G(1050, vector<char> (1050, ' '));
	G[1][1]='/'; G[1][2]='\\';
	G[2][1]='/'; G[2][2]='_'; G[2][3]='_'; G[2][4]='\\';
	int v=2;
	for(int i=2; i<=n; i++){
		for(int j=1; j<=v; j++){
			int p=j*2;
			for(int t=1; t<=p; t++)
				G[v+j][t]=G[j][t];
			for(int t=p+1; t<=2*(v+j-p); t++)
				G[v+j][t]=' ';
			for(int t=2*(v+j)-p+1; t<=2*(v+j); t++)
				G[v+j][t]=G[j][t+p-2*(v+j)];
		}
		v*=2;
	}
	for(int i=1; i<=pow(2, n); i++){
		for(int j=1; j<=pow(2, n)-i; j++){
			cout << " ";
		}
		for(int j=1; j <= 2*i; j++){
			if(G[i][j]==0) cout << " ";
			else cout << G[i][j];
		}
		for(int j=1; j<=pow(2, n)-1; j++)
			cout << " ";
		cout << endl;
	}
	return 0;
} 
