#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int rchild, lchild;
	int weight;
	int sign;                //标记，懒节点 
}; 

class IntervalTree {
	vector<Node> tree;
	
	void IntervalTree1 (vector<int> &nums, int &n, int k, int l, int r){
		tree[k].lchild = l; tree[k].rchild = r;
		if (tree[k].lchild == tree[k].rchild){
			tree[k].weight = nums[n++];
			return;
		}
		int mid = l + (r - l) / 2;
		IntervalTree1 (nums, n, k * 2, l, mid);
		IntervalTree1 (nums, n, k * 2 + 1, mid + 1, r);
		tree[k].weight = tree[k*2].weight + tree[k*2+1].weight;
		
	}
	public:
		IntervalTree(vector<int> &nums)
		{
			tree.resize(nums.size() * 2);  
			int t = nums.size()-1;
			int n = 0;
			IntervalTree1(nums, n, 1, 1, t)
		}
		void down (int k)
		{
			tree[k*2].sign += tree[k].sign;
			tree[k*2+1].sign += tree[k].sign;
			tree[k*2].weight += tree[k*2].sign * (tree[k*2].rchild - tree[k*2].lchild + 1);
			tree[k*2+1].weight += tree[k*2+1].sign * (tree[k*2+1].rchild - tree[k*2+1].lchild + 1);
			tree[k].sign = 0;
		}
		void askPoint (int k, int &ans, int x)
		{
			if (tree[k].rchild == tree[k].lchild)
			{
				ans = tree[k].weight;
				return;
			}
			if(tree[k].sign) down(k);
			int mid = (tree[k].lchild + (tree[k].rchild - tree[k].lchild) / 2);
			if (x > mid)
			askPoint(k*2+1, ans, x);
			else
			askPoint(k*2, ans, x);
			
		}
		void changePoint(int k, int x, int after)
		{
			if (tree[k].rchild == tree[k].lchild)
			{
				tree[k].weight += after;
				return;
			}
			if(tree[k].sign) down(k);
			int mid = (tree[k].lchild + (tree[k].rchild - tree[k].lchild) / 2);
			if (x > mid)
			changePoint(k*2+1, x, after);
			else
			changePoint(k*2, x, after);
			tree[k].weight = tree[k*2].weight + tree[k*2+1].weight;
		}
		void askInterval(int k, int& x, int& y, int& ans)
		{
			if (tree[k].rchild <= y && tree[k].lchild >= x)
			{
				ans += tree[k].weight;
				return;
			}
			if(tree[k].sign) down(k);
			int mid = (tree[k].lchild + (tree[k].rchild - tree[k].lchild) / 2);
			if (x <= mid)
			askInterval(k*2, x, y, ans);
			if (y > mid)
			askInterval(k*2+1, x, y, ans);
		}
		void changeInterval (int k, int &x, int &y, int &after)
		{
			if (tree[k].rchild <= y && tree[k].lchild >= x)
			{
				tree[k].weight += (tree[k].rchild - tree[k].lchild + 1 ) * after;
        		tree[k].sign += after;
        		return;

			}
			if(tree[k].sign) down(k);
			int mid = (tree[k].lchild + (tree[k].rchild - tree[k].lchild) / 2);
			if (x <= mid)
			changeInterval(k*2, x, y, after);
			if (y > mid)
			changeInterval(k*2+1, x, y, after); 
			tree[k].weight = tree[k*2].weight + tree[k*2+1].weight;
		}
		void print ()
		{
			cout << "序列：\t" ; 
			for (int i = 1; i < tree.size()-1; i++)
			{
				cout << i << "\t";
			}
			cout << endl;
			cout << "lchild：\t" ; 
			for (int i = 1; i < tree.size()-1; i++)
			{
				cout << tree[i].lchild << "\t";
			}
			cout << endl;
			cout << "rchild：\t" ; 
			for (int i = 1; i < tree.size()-1; i++)
			{
				cout << tree[i].rchild << "\t";
			}
			cout << endl;
			cout << "weight：\t" ; 
			for (int i = 1; i < tree.size()-1; i++)
			{
				cout << tree[i].weight << "\t";
			}
			cout << endl;
			cout << "sign：\t" ; 
			for (int i = 1; i < tree.size()-1; i++)
			{
				cout << tree[i].sign << "\t";
			}
			cout << endl;
		}
};

int main ()
{
	vector<int> nums;
	for (int i = 0;i < 6; i++)
		nums.push_back (i+2);
	IntervalTree test (nums);
	test.print();
 } 
