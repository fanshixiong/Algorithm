#include <iostream>
#include <vector>
using namespace std;
                                                            //单调队列用于求区间最值  
struct Node{
	int data;          //元素 
	int x;            //下标 
}humque[10000];

void getMin (vector<int> &min, vector<int> &nums, int m){   //min保存区间最小值 ，m为区间 
	int head = 0, tail = 0;                               //head 队列头 tail队列尾 
	humque[tail].data = nums[0]; 
	humque[tail].x = 0; 
	for (int i = 1; i < m-1; i++){                           //将m-1个元素赋初值到单调队列中 
		while (tail > head && nums[i] <= humque[tail].data) tail--;  //满足单调性 
		humque[++tail].data = nums[i]; 
		humque[tail].x = i;
	}
	for (int i = m-1; i < nums.size() ; i++){
		while (tail >= head && nums[i] <=humque[tail].data) tail--;
		//cout << tail << endl;
		humque[++tail].data = nums[i];
		humque[tail].x = i;
		while (humque[head].x < i-m+1) head++;        //将超出区间范围的元素剔除 
		min[i-m+1] = humque[head].data;             // 单调队列头元素即为最小值 

	}
}
//同理 
void getMax(vector<int> &max, vector<int> &nums, int m){
	int head = 0, tail = 0;
	humque[tail].data = nums[0]; 
	humque[tail].x = 0; 
	for (int i = 1; i < m-1; i++){
		while (tail > head && nums[i] >= humque[tail].data) tail--;
		humque[++tail].data  = nums[i];
		humque[tail].x = i;
	}
	for (int i = m-1; i < nums.size(); i++){
		while (tail >= head && nums[i] >= humque[tail].data ) tail--;
		humque[++tail].data = nums[i];
		humque[tail].x = i;
		while (humque[head].x < i-m+1) head++;
		max[i-m+1] = humque[head].data ;
	}
}


int main(){
	vector<int> max(7);
	vector<int> min(7);
	vector<int> nums;
	for (int i = 0; i < 3; i++)
		nums.push_back(i+3);
	nums.push_back(-1);
	nums.push_back(7);
	nums.push_back(-5);
	nums.push_back(4);
	getMin (min, nums, 3);
	for (int i = 0; i <= min.size()-3; i++){
		cout << min[i] <<" " ;
	}
	return 0;
}
