#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int n;
int maze[3][3];
int main(){
	vector<int> row(4), col(4), lie(4);
	vector<int> rn(4), cn(4); 

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cin >> maze[i][j];
			if(maze[i][j]){
				row[i]+=maze[i][j];
				col[j]+=maze[i][j];
				rn[i]++; cn[j]++;
			}
		}
	}
	row[1]=col[1]=lie[1]=lie[2]=5;
	rn[1]=cn[1]=1;
	maze[1][1]=5;
	for(int i=0;  i<3; i++){
		for(int j=0; j<3; j++){
			if(maze[i][j]){
				int x=i, y=j;
				if(i==0 && j==0)
					x=2, y=2;
				if(i==2 && j==2)
					x=0, y=0;
				if(i==1 && j==0)
					x=1, y=2;
				if(i==0 && j==1)
					x=2, y=1;
				if(i==0 && j==2)
					x=2, y=0;
				if(i==2 && j==0)
					x=0, y=2;
				if(i==1 && j==2)
					x=1, y=0;
				if(i==2 && j==1)
					x=0, y=1;
				if(!maze[x][y]){
					maze[x][y] = 10-maze[i][j];
					row[x]+=maze[x][y];
					col[y]+=maze[x][y];
					rn[x]++; cn[y]++;
				}
			}
		}
	}
	//cout << maze[1][0] << endl;
	int k=8;
	while(k--){
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(!maze[i][j]){
					if(rn[i]==2){ //cout << "row" << i << " " << j << " "<<row[i] << " " << rn[i] << endl;
						maze[i][j]=15-row[i];
						row[i]+=maze[i][j];
						col[j]+=maze[i][j];
						rn[i]++;cn[j]++;
					}
					else if(cn[j]==2){ //cout <<"col"<< i << " " << j << " "<<col[j] << " " << cn[j] << endl;
						maze[i][j]=15-col[j];
						row[i]+=maze[i][j];
						col[j]+=maze[i][j];
						rn[i]++;cn[j]++;
					}
				}
			}
		}
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
} 

