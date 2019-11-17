#include<iostream>
#include<deque>
#include <map>
#include <cmath>
using namespace std;
map<string, int> mmp;
int dist[4] = {1, 2, -1, -2};
struct Zham{
	string s;
	int num;
	int pos;
};
void bfs(){
	Zham x;
	x.num = 0; x.s = "012345678"; x.pos = 0;
	deque<Zham> q;
	q.push_back(x);
	mmp["012345678"]++;
	int num = 0;
	while (!q.empty()){
		Zham tmp = q.front();
		q.pop_front();
		if (tmp.s == "087654321"){
			cout << tmp.num <<endl;
			return;
		}
		
		for (int i = 0; i < 4; i++){
			int d = dist[i] + tmp.pos;
			if (d < 0)
				d += 9;
			if (d > 8)
				d -= 9;
			string str = tmp.s;
			str[tmp.pos] = str[d]; str[d] = '0';
			if (!mmp[str]){
				mmp[str]++;
				cout << str << endl;
				Zham temp;
				temp.s = str; temp.pos = d; temp.num = tmp.num+1;
				q.push_back(temp);
			}
		}
	}
}
int main(){
	bfs();
	return 0;
} 
