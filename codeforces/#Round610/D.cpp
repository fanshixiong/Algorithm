#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
	cout << "a" << endl;
	int sa;
	cin >> sa;
	if(sa == 300){
		string s = "";
		for (int i = 0; i < 300; i++)
			s += "b";
		cout << s << endl;
		return 0;
	}
	string now = "a";
	int score = sa;
	for (int i = 0; i < score; i++)	{
		now += "a";
	}
	cout << now << endl;
	int len = score;
	int nextScore;
	cin >> nextScore;
	if(nextScore > score){
		string s;
		for(int i=0; i<len; i++){
			s += "b";
		}
		cout << s << endl;
		return 0;
	}
	score = nextScore;
	if(score == 0)
		return 0;
	for (int i = 0; i < now.size(); i++){
		now[i] = 'b';
		cout << now << endl;
		cin >> nextScore;
		if(nextScore == 0){
			return 0;
		}
		if(nextScore > score){
			now[i] = 'a';
		}
		score = min(nextScore, score);
	}
		return 0;
}