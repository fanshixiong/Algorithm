#include<bits/stdc++.h>

using namespace std;
class JobNode{
	friend void Greedy(JobNode* , int, int );
	friend void main(void);
	public:
		operator int () const{return time;}
	private:
		int Id, time; 	
};
class MachineNode{
	friend void Greedy(JobNode*, int, int);
	public:
		operator int ()const{return avail;}
	private:
		int Id, avail;
};
void Greedy(vector<int> a, int n, int m){
	if ( n<= m){
		cout << "为每一个作业分配一个机器！" << endl;
		return; 
	}
	sort(a.begin(), a.end());
	MinHeap<MachineNode> H(m);
	MachineNode x;
	for (int i = 1; i <= m; i++){
		x.avail = 0;
		x.Id = i;
		H.insert(x);
	}
	for (int i = n; i >= 1; i--){
		H.DeleteMin(x);
		cout << "将机器" << x.Id << "从" << x.avail << "到" << (x.avail + a[i].time) << "的时间段分配给作业" << a[i].Id<< endl;
		x.avail += a[i].time;
		H.insert(x); 
	}
}
int main(){
	
	return 0;
}
