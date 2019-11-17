/*���ű����Ź����ţ�
�����������������⣻��map��hash ����չ������  �����ٵİ��� 
����ԭ�� û�п�������߽����   ��ݲ�һ��һ���ܹ����� 
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int FAC[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int d[4][2] ={-1,0,1,0,0,-1,0,1}; 
vector<int> vis(400000);
struct pos{
	int x, y; //���� 
	int step; //��ǰ���� 
	string s; //�ַ��� 
	pos(int m, int n, int s, string ss):x(m), y(n), step(s), s(ss){
	}
};
bool cantor(string &s){
	vector<int> nums;
	for (int i = 0; i < 9; i++){
		if (s[i] != '.')
			nums.push_back(s[i]-'0'); 
		else
			nums.push_back(9); 
	}
	int res = 0;
	for (int i = 0; i < 8; i++){
		int small = 0;
		for (int j = i+1; j < 9; j++){
			if (nums[i] > nums[j])
				small++;
		}
 		res += small * FAC[8-i];
	}
//	cout << res <<endl;
	bool b = 0;
	if (!vis[res])
		vis[res]++;
	else
		b=1;
	return b;
}
int main(){
	freopen("in.txt", "r", stdin);
	string s, target; cin >> s >> target;
	queue<pos> q;
	q.push(pos(2, 2, 0, s));
	cantor(s);
	int step = 0;
	while (!q.empty() ){
		pos p = q.front();
		q.pop(); 
		cout << p.s << " " << p.step <<endl;
		if (p.s == target){
			step = p.step;
			break;
		}
		for (int i = 0; i < 4; i++){
			if (p.x+d[i][0]>=0 && p.x+d[i][0] < 3 && p.y+d[i][1] >=0 && p.y+d[i][1] < 3){
				int bef = p.x * 3 + p.y;                  //֮ǰ.��λ�� 
				int tmpx = p.x +d[i][0];
				int tmpy = p.y +d[i][1];
				int post = tmpx*3+tmpy;                //�ı�֮�� . ��λ�� 
				string tmps = p.s;
				tmps[bef] = p.s[post]; tmps[post] = '.';
				//cout << bef << "     " << post << "          " << tmps << endl;
				int tmpstep = p.step + 1;
				pos tmp(tmpx, tmpy, tmpstep, tmps);
				if (!cantor(tmp.s)){
					q.push(tmp);
				}
			}
		}
	} 
	if (step != 0)cout << step << endl;
	else cout << -1 << endl;
	return 0;
}

