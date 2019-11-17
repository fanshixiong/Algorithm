#include <iostream>
#include <vector>
int MAX = 10000;
using namespace std;
int w(int i, int k, int j, vector<vector<int> > &mmp){
	return mmp[i][j]+mmp[i][k]+mmp[j][k];
}
void MinWeightTrianglation(int n, vector<vector<int> > &nums, vector<vector<int> > &s, vector<vector<int> > &mmp){
	for(int r = 2; r <= n; r++){
		for(int i = 1; i <= n-r+1; i++){
			int j = i+r-1;
			nums[i][j] = nums[i+1][j] + w(i-1, i, j, mmp);
			s[i][j] = i;
			for(int k = i+1; k < i + r -1; k++){
				int u = nums[i][k] + nums[k+1][j] + w(i-1, k, j, mmp);
				if (u < nums[i][j]) {
					nums[i][j] = u;
					s[i][j] = k;
				}
			}
		}
	}
}

void Traceback (int i, int j, vector<vector<int> > &s){
	if (j == i) return;
	Traceback (i, s[i][j], s);
	Traceback (s[i][j] +1, j, s);
	cout << i << " " << s[i][j] << ", "<< s[i][j] + 1 << " " << j  << endl;
}

int main (){
	vector<vector<int> > mmp(6, vector<int> (6));
	for (int i = 1; i <= 5; i++)
	for (int j = i; j <= 5; j++)
	{	
		mmp[i][j] = j;
		mmp[j][i] = j;
	}
	for (int i = 1; i <= 5; i++)
	mmp[i][i] = MAX;
	vector<vector<int> > s(6, vector<int> (6));
	vector<vector<int> > nums(6, vector<int> (6));
	
	MinWeightTrianglation (5, nums, s, mmp);
	Traceback (1, s.size()-1 , s);
	system("pause");
}
