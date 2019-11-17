/*Ð¡À¶Èü£º ¿¾¼¦ 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

string inttostr(vector<int> &num){
	string s;
	for (int i = 0; i < 10; i++){
		s += num[i]+'0';
	}
	return s;
}
int main(){
	int n;
	cin >> n;
	vector<vector<int> > end;
	if (n < 10 || n > 30) cout << 0 << endl;
	else{
		int res = 1;
		n -= 10;
		if (n <= 10){
			vector<int> nums(10, 1);
			map<string, int> mmp;
			end.push_back(nums);
			int m = n;
			while (m-- > 0){
				int p = end.size();
				map<string, int> mp1;
				for (int i = 0; i < p; i++){
					vector<int> num(10);
					for (int m = 0; m < 10; m++)
						num[m] = end[0][m];
					end.erase(end.begin());  
					/*if (mmp[s]){
						end.erase(end.begin() + i-1);
						continue; 
					}
					mmp[s]++;*/
					for (int j = 0; j < 10; j++){
						if (num[j] + 1 <= 3){
							num[j]++;
							string s = inttostr(num);
							if (!mmp[s]){
								end.push_back(num);
								mmp[s]++;
							}
							num[j]--;
						}
					}
				}
				/*
				for (int i = 0; i < end.size(); i++){
					string s = inttostr(end[i]);
					if (mp1[s]){
						res--;
						end.erase(end.begin() + i);
						i--; 
					}
					mp1[s]++;
				}*/
			}
		}
		else{
			vector<int> nums(10, 3);
			map<string, int> mmp;
			end.push_back(nums);
			int m = n;
			while (m++ < 20){
				int p = end.size();
				for (int i = 0; i < p; i++){
					vector<int> num(10);
					for (int m = 0; m < 10; m++)
						num[m] = end[0][m];
					
					end.erase(end.begin());
					for (int j = 0; j < 10; j++){
						if (num[j] - 1 > 0){
							num[j]--;
							string s = inttostr(num);
							if (!mmp[s]){
								end.push_back(num);
								mmp[s]++;
							}
							num[j]++;
						}
					}
				}
			}
		}
		res = end.size();
		sort(end.begin(), end.end());
		cout << res << endl;
		for (int i = 0; i < end.size(); i++){
			for (int j = 0; j < 10; j++)
				cout << end[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}


/*
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > res;
vector<int> num(10);
int n, res_num = 0;
void chicken(int total, int depth){
	if(depth == 10){
		if (total == n){
			res.push_back(num);
			res_num++;
		}
	}
	else if (total >= n)
		return;
	else{
		for (int i = 1; i <= 3; i++){
			num[depth] = i;
			chicken(total+i, depth+1);
		}
	}
	return;
}
int main(){
	cin >> n;
	if (n < 10 || n > 30) cout << 0 << endl;
	chicken(0, 0);
	cout << res_num << endl;
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < 10; j++)
				cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}*/

