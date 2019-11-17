/*  蓝桥杯  青蛙跳杯子  
分析：BFS广搜  注意判断步数 
*/ 

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
int d[6] = {-1, -2, -3, 1, 2, 3};
int Path(string str, string target){                          //BFS
	queue<string> q;                                         //初始化 
	q.push(str);
	map<string, int> mmp;                                    //代表字符串是否出现过 
	mmp[str]++;
	int pos = str.find('*') ;
	while (!q.empty()){
		string ss = q.front();
		q.pop();
		pos = ss.find('*');
		if (ss == target) return mmp[ss];                  //找到返回 
		for (int i = 0; i < 6; i++){
			if ((pos+d[i]>=0) && (pos+d[i] < ss.size())){
				string s1 = ss;
				s1[pos] = s1[pos+d[i]]; s1[pos+d[i]] = '*';
				/*if(!mmp.count(s1)){
					q.push(s1); 
					mmp[s1]++;
				}*/
				if (!mmp.count(s1)) {
					q.push(s1); 
					mmp[s1] = mmp[ss] + 1;
				} 
			}
		}
	}
	return -1;
}
int main(){
	freopen("in.txt", "r", stdin);
	string str, target; cin >> str >> target;
	cout << Path(str, target)-1<<endl;
	return 0;
}
