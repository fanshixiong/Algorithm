// 马的哈密顿回路问题： 
// 解决思路：分治，递归，图的dfs遍历，剪枝
// 

#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cstring>
#include <stdlib.h> 
using namespace std; 

typedef struct 
{
	int x;
	int y;
}Step;

Step step[8] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {1, -2}, {1, 2}, {-1, -2}, {-1, 2}};

struct NextPos{
	int nextPosStep;  //表示下一个位置有多少种走法，走法少的优先考虑
	int nextPosDirection; //表示下一个位置相对与当前位置的方位
	int nextPosToMidLength; //表示下一个位置距离中心点的距离 
	
	bool operator < (const NextPos &a)const
	{
		return nextPosStep > a.nextPosStep && nextPosToMidLength < a.nextPosToMidLength; 
	 } 
};

int board[100][100];
int M, N;  //棋盘大小 
//检测位置是否可走 
bool check (int x, int y)
{
	if (x >= 0  && x < M && y >= 0 && y < N && board[x][y] == 0)
		return true;
	return false;
}
//下一个位置有多少种走法 
int nextPosHasSteps (int x, int y)
{
	int steps = 0;
	for (int i = 0; i < 8; i++)
		if (check(x + step[i].x, y + step[i].y))
			steps++;
	return steps;
}
//是否能回到起点 
bool returnStart (int x, int y)
{
	int midx = M/2 - 1;
	int midy = M/2 - 1;
	for (int i = 0; i < 8; i++)
		if ((x + step[i].x == midx) && (y + step[i].y == midy))
			return true;
	return false;
}
//输出 
void outPutResult (int xstart, int ystart)
{
	int num = M * N;
	int k = num - board[xstart][ystart];
	for (int i = 0; i < M; i++)
	{
		cout << endl <<endl;
		for (int j = 0; j < N; j++)
		{
			board[i][j] = (board[i][j] + k ) % num + 1;
			cout << setw(5) << board[i][j] ;
		}
	}
	cout << endl << endl;
} 

//从某一位置距离棋盘中心的距离
int posToMidLength (int x, int y)
{
	int midx = M / 2 - 1;
	int midy = M / 2 - 1;
	return  (fabs (x - midx) + fabs (y - midy));
 } 
 
 // 主算法,回溯 
 void BackTrace (int t, int x, int y, int xstart, int ystart)
 {
 	if (t == M * N && returnStart (x, y))
 	{
 		outPutResult (xstart, ystart);
 		exit(1);
	 }
	 priority_queue<NextPos> nextPosQueue;
	 for (int i = 0; i < 8; i++)
	 {
	 	if (check (x + step[i].x , y + step[i].y ))
	 	{
	 		NextPos NextPos1;
	 		NextPos1.nextPosStep = nextPosHasSteps (x + step[i].x , y + step[i].y );
	 		NextPos1.nextPosToMidLength = posToMidLength (x + step[i].x , y + step[i].y );
	 		NextPos1.nextPosDirection = i;
	 		nextPosQueue.push(NextPos1);	 		
		 }
	 }
	 while (nextPosQueue.size())
	 {
	 	int d = nextPosQueue.top().nextPosDirection;
	 	nextPosQueue.pop() ;
	 	
	 	x += step[d].x;
	 	y += step[d].y;
	 	board[x][y] = t+1;
	 	
	 	BackTrace (t+1, x, y, xstart, ystart);
	 	board[x][y] = 0;
	 	x -= step[d].x;
	 	y -= step[d].y;
	 }
 }
 
 void horserun (int xstart, int ystart)
 {
 	//初始化棋盘
	memset (board, 0, M*N); 
 	int midx = M / 2 -1;
 	int midy = M / 2 -1;
 	
 	board[midx][midy] = 1;
 	BackTrace (1, midx, midy, xstart, ystart);
 	
 }
 
 int main ()
 {
 	int x, y;
 	cout << "请输入棋盘大小m*n|m-n|<=2 且 m和n都为偶数 且 m,n < 20 :";    
	cin >> M >> N;     
	cout << "请输入马周游起始位置--横纵坐标0 <= x < " << M << "和0 <= y < " << N << " :";    
	cin>> x >> y;     
	horserun (x, y);                                                      //执行马周游   
	return 0;
 }
 
