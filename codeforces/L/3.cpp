#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<iterator>
#include<time.h>
using namespace std;
#define MAX   4
int maze[9][9] =
{ { 1,1,1,1,1,1,1,1,1 },
{ 1,0,0,1,0,0,1,0,1 },
{ 1,1,0,1,1,0,0,0,1 },
{ 1,0,1,0,1,1,0,1,1 },
{ 1,0,0,0,0,1,0,0,1 },
{ 1,1,0,1,0,1,0,0,1 },
{ 1,1,0,1,0,1,0,0,1 },
{ 1,1,0,1,0,0,0,0,1 },
{ 1,1,1,1,1,1,1,1,1 },
};
int x, y, a, b, dis[MAX][MAX], visit[MAX][MAX];
int dfs(int x, int y);
int next(int a, int b, int x, int y)
{
	if (dis[x][y] > dis[a][b] + 1) //如果小于就要从这个点重新遍历
	{
		dis[x][y] = dis[a][b] + 1;//更新其值
		visit[x][y] = 0;//将状态设为可访问   这步比较重要
	}
	if (!visit[x][y]) { dfs(x, y); }
	return 0;
}
// 深度优先
int dfs(int x, int y)
{
	visit[x][y] = 1;
	if (x + 1 < 9 && maze[x + 1][y] == 0) //上
	{
		next(x, y, x + 1, y);
	}
	if (x - 1 >= 0 && maze[x - 1][y] == 0) //下
	{
		next(x, y, x - 1, y);
	}
	if (y + 1 < 9 && maze[x][y + 1] == 0) //左
	{
		next(x, y, x, y + 1);
	}
	if (y - 1 >= 0 && maze[x][y - 1] == 0) //右
	{
		next(x, y, x, y - 1);
	}
	return 0;
}
int main()
{
	
		memset(dis, 0x3f3f3f3f, sizeof(dis));//初始化将dis的值设的比较大
		memset(visit, 0, sizeof(visit));//初始化visit将所有值设为0
		cin >> x >> y >> a >> b;
		dis[x][y] = 0;
		clock_t start, finish;
		double totaltime;
		start = clock();
		dfs(x, y);
		cout << "\n所走步数为" <<  dis[a][b] << endl;
		finish = clock();
		totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
		cout << "\n此程序的运行时间为" << totaltime * 1000 << "毫秒！" << endl;
		cout << "起始状态为" << x << y << endl;
		cout << "目标状态为" << a << b << endl;
		system("pause");
	    return 0;
}
