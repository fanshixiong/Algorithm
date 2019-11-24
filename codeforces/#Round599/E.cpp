#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<iterator>
#include<ctime>

using namespace std;
int x, y, a, b;

struct  point
{
	int x, y;//x坐标y坐标步数
	struct point *w;
	struct point *n;
	struct point *e;
	struct point *s;
	bool state;
	void pt(int a, int b,struct point *w1,struct point *n1,struct point *e1,struct point *s1,bool state1){
		x=a;
		y=b;
		w=w1;
		n=n1;
		e=e1;
		s=s1;
		state=state1;
	}
};
void bfs(point tp)
{
	queue<point> open;
	queue<point> close;
	open.push(tp);
	if  (tp.x == a && tp.y == b) 
	{cout<<"Succeed!"<<endl;}
	while(!open.empty()){
		open.pop();
		
		tp.state = false;
	    if (tp.w != 0 && tp.w->state == true)
		{open.push(*tp.w); }
		if (tp.n != 0 && tp.n->state == true)
		{open.push(*tp.n); }			
		if (tp.e != 0 && tp.e->state == true)
		{open.push(*tp.e); }			
		if (tp.s != 0 && tp.s->state == true)
		{open.push(*tp.s); }
		tp = open.front( );
		if  (tp.x == a && tp.y == b)
		{
			cout<<"Succeed!"<<endl;
			struct point a ;
			while(!close.empty()){
				a = close.front();
				cout<<a.x << " "<<a.y << endl;
				close.pop();
			}
			break;
		}
	}
}

int main()
{
	struct point p[10];
	p[0].pt(1,1,0,&p[3],0,0,true);
	p[1].pt(1,4,0,0,&p[4],0,true);
	p[2].pt(2,2,0,&p[3],&p[6],&p[5],true);
	p[3].pt(2,3,&p[0],&p[4],0,&p[2],true);
	p[4].pt(2,4,&p[1],0,&p[8],&p[3],true);
	p[5].pt(3,1,&p[2],&p[6],&p[7],0,true);
	p[6].pt(3,2,&p[2],&p[7],0,&p[5],true);
	p[7].pt(3,3,0,&p[8],&p[5],&p[6],true);
	p[8].pt(3,4,&p[5],0,&p[9],&p[7],true);
	p[9].pt(4,4,&p[8],0,0,0,true);
	cin>>a>>b;
	clock_t startTime,endTime;
	startTime = clock();
	bfs(p[0]);
	endTime = clock();
	cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	cout <<"Start:   "<<p[0].x<<p[0].y<<endl;

	cout <<"End:  "<<p[9].x<<p[9].y<<endl;
	system("pause");
	return 0;
}