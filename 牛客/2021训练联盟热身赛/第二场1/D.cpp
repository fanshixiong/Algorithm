#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
struct node{
	string name;
	int points;
	int goal;
	int miss;
	int win;
	int tie;
	int loss;
}team[410];
int n, m;
bool cmp(const node a, const node b){
	if(a.points == b.points){
		if(a.goal-a.miss == b.goal-b.miss){
			if(a.goal == b.goal){
				return a.name < b.name;
			}
			return a.goal > b.goal;
		}
		return a.goal-a.miss > b.goal-b.miss;
	}
	return a.points > b.points;
}
void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		team[i].points = team[i].win = team[i].loss = team[i].tie = team[i].points = team[i].miss = team[i].goal = 0;
	}
	unordered_map<string, int> p;
	for(int i = 0; i < n; i++){ 
		string a; cin >> a;
		team[i].name = a; p[a] = i;
	}
	for(int i = 0; i < m; i++){
		int x, y;
		string a, b; 
		cin >> a >> x >> b >> y;
		if(x > y){
			team[p[a]].win ++;
			team[p[b]].loss ++;
			team[p[a]].points += 3;
		}
		else if(x < y){
			team[p[a]].loss ++;
			team[p[b]].win ++;
			team[p[b]].points += 3;
		}
		else {
			team[p[a]].tie ++;
			team[p[b]].tie ++;
			team[p[a]].points ++;
			team[p[b]].points ++;
		}
		team[p[a]].miss += y;
		team[p[a]].goal += x;

		team[p[b]].miss += x;
		team[p[b]].goal += y;
	}

	sort(team, team + n, cmp);
	for(int i = 0; i < n; i++){
		cout << team[i].name << " " << team[i].points << " " << team[i].win << " " << team[i].loss << " " << team[i].tie << " " << team[i].goal << " " << team[i].miss << endl;
	}
	cout << endl;
}
int main(){
    IOS; int t; cin >>t;
    int x = 0;
    while(x ++ < t){
    	cout << "Group " << x << ":" << endl;
        solve();
    }
    return 0;
}